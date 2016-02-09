#include "ofxFormConstantForce.h"

using namespace ofxTraerPhysics;

ofxFormConstantForce::ofxFormConstantForce(float f) : ofxForce(f) {
	mVerticalBands = false;
	mHorizontalBands = false;
	mArms = false;
	mRings = false;

	mNumVerticalBands = 0;
	mNumHorizontalBands = 0;
	mNumArms = 0;
	mNumRings = 0;
	mSpeed = 2;
}

ofxFormConstantForce::ofxFormConstantForce(float fx, float fy, float fz) : ofxForce(fx, fy, fz) {

}

ofxFormConstantForce::~ofxFormConstantForce() {

}

void ofxFormConstantForce::apply(std::shared_ptr<ofxParticle> p) {
	if (isOn()) {
		ofVec3f position = p.get()->getPosition();
		ofVec3f radialPosition = ofVec3f(position[0] * position[0] + position[1] * position[1], atan2(position[0], position[1]), 0);
		ofVec3f force = ofVec3f(0, 0, 0);

		if (mHorizontalBands) {
			force += ofVec3f(mScale[0] * cos(mNumHorizontalBands*position[0] + 0.0001*mSpeed*mTime), 0, 0);
		}
		if (mVerticalBands) {
			force += ofVec3f(0, mScale[1] * cos(mNumVerticalBands*position[1] + 0.0001*mSpeed*mTime), 0);
		}
		if (mRings) {
			force += ofVec3f(mScale[0] * position[0] * sin(0.5 * mNumRings * log(radialPosition[0]) + mSpeed*mTime) / radialPosition[0], mScale[1] * position[1] * sin(0.5 * mNumRings * log(radialPosition[0]) + mSpeed*mTime) / radialPosition[0], 0);
		}
		if (mArms) {
			force += ofVec3f(- mScale[0] * position[1] * sin(0.5 * mNumArms * radialPosition[1] + mSpeed*mTime) / radialPosition[0], mScale[1] * position[0] * sin(0.5 * mNumArms * radialPosition[1] + mSpeed*mTime) / radialPosition[0], 0);
		}

		p->addForce(force);
	}
}

void ofxFormConstantForce::horizontalBandsOn(int numBands) {
	mHorizontalBands = true;
	mNumHorizontalBands = numBands;
}

void ofxFormConstantForce::horizontalBandsOff() {
	mHorizontalBands = false;
}

void ofxFormConstantForce::verticalBandsOn(int numBands) {
	mVerticalBands = true;
	mNumVerticalBands = numBands;
}

void ofxFormConstantForce::verticalBandsOff() {
	mVerticalBands = false;
}

void ofxFormConstantForce::armsOn(int numArms) {
	mNumArms = numArms;
	mArms = true;
}

void ofxFormConstantForce::armsOff() {
	mArms = false;
}

void ofxFormConstantForce::ringsOn(int numRings) {
	mNumRings = numRings;
	mRings = true;
}

void ofxFormConstantForce::ringsOff() {
	mRings = false;
}