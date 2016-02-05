
#include "ofxAttractorForce.h"

std::shared_ptr<ofxAttractorForce> ofxAttractorForce::make(float f) {
	std::shared_ptr<ofxAttractorForce> force(new ofxAttractorForce(f));
	return force;
}

std::shared_ptr<ofxAttractorForce> ofxAttractorForce::make(float fx, float fy, float fz) {
	std::shared_ptr<ofxAttractorForce> force(new ofxAttractorForce(fx, fy, fz));
	return force;
}

ofxAttractorForce::~ofxAttractorForce() {

}

void ofxAttractorForce::apply(std::shared_ptr<ofxParticle> p) {
	if (isOn()) {
		float distanceSq = mPosition.distance(p.get()->getPosition());
		distanceSq *= distanceSq;

		if (distanceSq < mMinDistanceSq) {
			distanceSq = mMinDistanceSq;
		}
		else if (distanceSq > mMaxDistanceSq) {
			distanceSq = mVeryFarAway;
		}

		float forceConstant = p->getMass() / distanceSq;

		ofVec3f unitVector = mPosition - p.get()->getPosition();
		unitVector.normalize();

		unitVector[0] *= forceConstant*mScale[0];
		unitVector[1] *= forceConstant*mScale[1];
		unitVector[2] *= forceConstant*mScale[2];

		p.get()->addForce(unitVector);
	}
}

ofVec3f ofxAttractorForce::getPosition() {
	return mPosition;
}

void ofxAttractorForce::setPosition(float x, float y, float z) {
	mPosition = ofVec3f(x, y, z);
}

ofxAttractorForce::ofxAttractorForce(float f) : ofxForce(f) {
	mPosition = ofVec3f(0, 0, 0);
}

ofxAttractorForce::ofxAttractorForce(float fx, float fy, float fz) : ofxForce(fx, fy, fz) {
	mPosition = ofVec3f(0, 0, 0);
}