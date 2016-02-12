#include "ofxOrbitalForce.h"

using namespace ofxTraerPhysics;

ofxOrbitalForce::ofxOrbitalForce(float f) : ofxForce(f) {
	mMinDistance = 25;
	mMaxDistance = 100;
	mVeryFarAway = 10000000000;
	mPosition = ofVec3f(0, 0, 0);
}

ofxOrbitalForce::~ofxOrbitalForce() {

}

void ofxOrbitalForce::apply(std::shared_ptr<ofxParticle> p) {
	if (isOn()) {
		float distance = mPosition.distance(p->getPosition());

		if (distance < mMinDistance) {
			distance = mMinDistance;
		}
		else if (distance > mMaxDistance) {
			distance = mVeryFarAway;
		}

		float forceConstant = p->getMass() / distance;

		ofVec3f unitVector = mPosition - p->getPosition();
		unitVector = ofVec3f(unitVector[1], -unitVector[0], 0);
		unitVector.normalize();
		
		unitVector[0] *= forceConstant*mScale[0];
		unitVector[1] *= forceConstant*mScale[1];
		unitVector[2] *= forceConstant*mScale[2];

		p->setVelocity(unitVector);
	}
}

ofVec3f ofxOrbitalForce::getPosition() {
	return mPosition;
}

void ofxOrbitalForce::setPosition(float x, float y, float z) {
	mPosition = ofVec3f(x, y, z);
}

void ofxOrbitalForce::setMinDistance(float distance) {
	mMinDistance = distance;
}

void ofxOrbitalForce::setMaxDistance(float distance) {
	mMaxDistance = distance;
}