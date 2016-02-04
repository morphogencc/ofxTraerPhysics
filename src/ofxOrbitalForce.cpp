#include "stdafx.h"
#include "ofxOrbitalForce.h"

ofxOrbitalForce::ofxOrbitalForce(float f) : ofxForce(f) {
	mMinDistance = 25;
	mMaxDistance = 100;
	mVeryFarAway = 10000000000;
	mPosition = pfVec3(0, 0, 0);
}

ofxOrbitalForce::~ofxOrbitalForce() {

}

void ofxOrbitalForce::apply(std::shared_ptr<ofxParticle> p) {
	if (isOn()) {
		float distance = mPosition.distance(p.get()->getPosition());

		if (distance < mMinDistance) {
			distance = mMinDistance;
		}
		else if (distance > mMaxDistance) {
			distance = mVeryFarAway;
		}

		float forceConstant = p->getMass() / distance;

		pfVec3 unitVector = mPosition - p.get()->getPosition();
		unitVector = pfVec3(unitVector[1], -unitVector[0], 0);
		unitVector.normalize();
		
		unitVector[0] *= forceConstant*mScale[0];
		unitVector[1] *= forceConstant*mScale[1];
		unitVector[2] *= forceConstant*mScale[2];

		p.get()->setVelocity(unitVector);
	}
}

pfVec3 ofxOrbitalForce::getPosition() {
	return mPosition;
}

void ofxOrbitalForce::setPosition(float x, float y, float z) {
	mPosition = pfVec3(x, y, z);
}

void ofxOrbitalForce::setMinDistance(float distance) {
	mMinDistance = distance;
}

void ofxOrbitalForce::setMaxDistance(float distance) {
	mMaxDistance = distance;
}