#include "stdafx.h"
#include "ofxAttractorForce.h"

ofxAttractorForce::ofxAttractorForce(float f) : ofxForce(f) {
	mMinDistance = 25;
	mMaxDistance = 100;
	mMinDistanceSq = mMinDistance*mMinDistance;
	mMaxDistanceSq = mMaxDistance*mMaxDistance;
	mVeryFarAway = 1000000000000000;
	mPosition = pfVec3(0, 0, 0);
}

ofxAttractorForce::ofxAttractorForce(float fx, float fy, float fz) : ofxForce(fx, fy, fz) {

}

ofxAttractorForce::~ofxAttractorForce() {

}

void ofxAttractorForce::apply(std::shared_ptr<ofxParticle> p) {
	if (isOn()) {
		float distanceSq = mPosition.distance(p.get()->getPosition());
		distanceSq *= distanceSq;

		if (distanceSq < mMinDistanceSq) {
			distanceSq = mMinDistance;
		}
		else if (distanceSq > mMaxDistanceSq) {
			distanceSq = mVeryFarAway;
		}

		float forceConstant = p->getMass() / distanceSq;

		pfVec3 unitVector = mPosition - p.get()->getPosition();
		unitVector.normalize();

		unitVector[0] *= forceConstant*mScale[0];
		unitVector[1] *= forceConstant*mScale[1];
		unitVector[2] *= forceConstant*mScale[2];

		p.get()->addForce(unitVector);
	}
}

pfVec3 ofxAttractorForce::getPosition() {
	return mPosition;
}

void ofxAttractorForce::setPosition(float x, float y, float z) {
	mPosition = pfVec3(x, y, z);
}

void ofxAttractorForce::setMinDistance(float distance) {
	mMinDistance = distance;
	mMinDistanceSq = distance*distance;
}

void ofxAttractorForce::setMaxDistance(float distance) {
	mMaxDistance = distance;
	mMaxDistanceSq = distance*distance;
}