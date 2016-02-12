#include "ofxSeparateForce.h"

using namespace ofxTraerPhysics;

std::shared_ptr<ofxSeparateForce> ofxSeparateForce::make(std::shared_ptr<ofxParticleSystem> particleSystem, float f) {
	std::shared_ptr<ofxSeparateForce> force(new ofxSeparateForce(particleSystem, f));
	return force;
}

std::shared_ptr<ofxSeparateForce> ofxSeparateForce::make(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz) {
	std::shared_ptr<ofxSeparateForce> force(new ofxSeparateForce(particleSystem, fx, fy, fz));
	return force;
}

ofxSeparateForce::ofxSeparateForce(std::shared_ptr<ofxParticleSystem> particleSystem, float f) : ofxForce(f) {
	mParticleSystem = particleSystem;
	mDesiredSeparation = 25.0;
}

ofxSeparateForce::ofxSeparateForce(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz) : ofxForce(fx, fy, fz) {
	mParticleSystem = particleSystem;
	mDesiredSeparation = 25.0;
}

ofxSeparateForce::~ofxSeparateForce() {

}

void ofxSeparateForce::setDesiredSeparation(float separation) {
	mDesiredSeparation = separation;
}

float ofxSeparateForce::getDesiredSeparation() {
	return mDesiredSeparation;
}

void ofxSeparateForce::apply(std::shared_ptr<ofxParticle> p) {
	ofVec3f steeringVector;
	for (auto particle : mParticleSystem->getParticles()) {
		float distance = p->getPosition().distance(particle->getPosition());
		if (distance < mDesiredSeparation && distance > 0) {
			ofVec3f difference = p->getPosition() - particle->getPosition();
			//difference.normalize();
			if (distance < mMinDistance) {
				distance = mMinDistance;
			}
			else if (distance > mMaxDistance) {
				distance = mVeryFarAway;
			}

			difference /= distance; // weight the force linearly by distance
			steeringVector += difference;
		}
	}

	steeringVector.normalize();
	steeringVector *= mScale;
	steeringVector -= p->getVelocity();
	p->addForce(steeringVector);
}