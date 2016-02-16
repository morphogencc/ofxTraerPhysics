#include "ofxAlignmentForce.h"

using namespace ofxTraerPhysics;

std::shared_ptr<ofxAlignmentForce> ofxAlignmentForce::make(std::shared_ptr<ofxParticleSystem> particleSystem, float f) {
	std::shared_ptr<ofxAlignmentForce> force(new ofxAlignmentForce(particleSystem, f));
	return force;
}

std::shared_ptr<ofxAlignmentForce> ofxAlignmentForce::make(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz) {
	std::shared_ptr<ofxAlignmentForce> force(new ofxAlignmentForce(particleSystem, fx, fy, fz));
	return force;
}

ofxAlignmentForce::ofxAlignmentForce(std::shared_ptr<ofxParticleSystem> particleSystem, float f) : ofxForce(f) {
	mParticleSystem = particleSystem;
	mNeighborDistance = 50.0;
}

ofxAlignmentForce::ofxAlignmentForce(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz) : ofxForce(fx, fy, fz) {
	mParticleSystem = particleSystem;
	mNeighborDistance = 50.0;
}

ofxAlignmentForce::~ofxAlignmentForce() {

}

void ofxAlignmentForce::setNeighborDistance(float separation) {
	mNeighborDistance = separation;
}

float ofxAlignmentForce::getNeighborDistance() {
	return mNeighborDistance;
}

void ofxAlignmentForce::apply(std::shared_ptr<ofxParticle> p) {
	ofVec3f steeringVector;
	for (auto particle : mParticleSystem->getParticles()) {
		float distance = p->getPosition().distance(particle->getPosition());
		if (distance > mNeighborDistance && distance > 0) {
			steeringVector += particle->getVelocity();
		}
	}

	steeringVector.normalize();
	steeringVector *= mScale;
	steeringVector -= p->getVelocity();
	p->addForce(steeringVector);
}