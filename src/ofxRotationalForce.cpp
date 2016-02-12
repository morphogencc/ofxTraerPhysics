#include "ofxRotationalForce.h"

using namespace ofxTraerPhysics;

ofxRotationalForce::ofxRotationalForce(float f) : ofxForce(f) {
	mMinDistance = 25;
	mMaxDistance = 100;
	mVeryFarAway = 10000000000;
	mPosition = ofVec3f(0, 0, 0);
}

ofxRotationalForce::~ofxRotationalForce() {

}

void ofxRotationalForce::apply(std::shared_ptr<ofxParticle> p) {
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
		unitVector.normalize();
		//unitVector = unitVector.perpendicular();

		unitVector[0] *= forceConstant*mScale[0];
		unitVector[1] *= forceConstant*mScale[1];
		unitVector[2] *= forceConstant*mScale[2];

		p->addForce(unitVector);
	}
}

ofVec3f ofxRotationalForce::getPosition() {
	return mPosition;
}

void ofxRotationalForce::setPosition(float x, float y, float z) {
	mPosition = ofVec3f(x, y, z);
}

void ofxRotationalForce::setMinDistance(float distance) {
	mMinDistance = distance;
}

void ofxRotationalForce::setMaxDistance(float distance) {
	mMaxDistance = distance;
}