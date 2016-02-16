#include "ofxCohesiveForce.h"

using namespace ofxTraerPhysics;

std::shared_ptr<ofxCohesiveForce> ofxCohesiveForce::make(std::shared_ptr<ofxParticleSystem> particleSystem, float f) {
	std::shared_ptr<ofxCohesiveForce> force(new ofxCohesiveForce(particleSystem, f));
	return force;
}

std::shared_ptr<ofxCohesiveForce> ofxCohesiveForce::make(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz) {
	std::shared_ptr<ofxCohesiveForce> force(new ofxCohesiveForce(particleSystem, fx, fy, fz));
	return force;
}

ofxCohesiveForce::ofxCohesiveForce(std::shared_ptr<ofxParticleSystem> particleSystem, float f) : ofxForce(f) {
	mParticleSystem = particleSystem;
	mNeighborDistance = 50.0;
}

ofxCohesiveForce::ofxCohesiveForce(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz) : ofxForce(fx, fy, fz) {
	mParticleSystem = particleSystem;
	mNeighborDistance = 50.0;
}

ofxCohesiveForce::~ofxCohesiveForce() {

}

void ofxCohesiveForce::setNeighborDistance(float separation) {
	mNeighborDistance = separation;
}

float ofxCohesiveForce::getNeighborDistance() {
	return mNeighborDistance;
}

void ofxCohesiveForce::apply(std::shared_ptr<ofxParticle> p) {
	ofVec3f flockCentroid = ofVec3f(0, 0, 0);
	ofVec3f steeringVector = ofVec3f(0, 0, 0);

	for (auto particle : mParticleSystem->getParticles()) {
		float distance = p->getPosition().distance(particle->getPosition());
		if (distance > mNeighborDistance && distance > 0) {
			flockCentroid += particle->getPosition();
		}
	}

	flockCentroid /= mParticleSystem->getNumberOfParticles();

	steeringVector = flockCentroid - p->getPosition();
	steeringVector.normalize();
	steeringVector *= mScale;
	steeringVector -= p->getVelocity();

	p->addForce(steeringVector);

}