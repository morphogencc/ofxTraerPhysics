#include "ofxSeekerForce.h"

using namespace ofxTraerPhysics;

std::shared_ptr<ofxSeekerForce> ofxSeekerForce::make(float f) {
	std::shared_ptr<ofxSeekerForce> force(new ofxSeekerForce(f));
	return force;
}

std::shared_ptr<ofxSeekerForce> ofxSeekerForce::make(float fx, float fy, float fz) {
	std::shared_ptr<ofxSeekerForce> force(new ofxSeekerForce(fx, fy, fz));
	return force;
}

ofxSeekerForce::ofxSeekerForce(float f) : ofxForce(f) {
	mTarget = ofVec3f(0,0,0);
}

ofxSeekerForce::ofxSeekerForce(float fx, float fy, float fz) : ofxForce(fx, fy, fz) {
	mTarget = ofVec3f(0,0,0);
}

ofxSeekerForce::~ofxSeekerForce() {

}

void ofxSeekerForce::setTarget(ofVec3f target) {
	mTarget.set(target);
}

ofVec3f ofxSeekerForce::getTarget() {
	return mTarget;
}

void ofxSeekerForce::apply(std::shared_ptr<ofxParticle> p) {
	ofVec3f flockCentroid = ofVec3f(0, 0, 0);
	ofVec3f steeringVector = ofVec3f(0, 0, 0);

	steeringVector = mTarget - p->getPosition();
	steeringVector.normalize();
	steeringVector *= mScale;
	steeringVector -= p->getVelocity();

	p->addForce(steeringVector);
}