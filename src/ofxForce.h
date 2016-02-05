#pragma once

#include "ofxParticle.h"

class ofxForce {
public:
	~ofxForce() {
	};

	void turnOn() {
		mIsOn = true;
	};

	void turnOff() {
		mIsOn = false;
	};

	bool isOn() {
		return mIsOn;
	};

	void setScale(float fx, float fy, float fz) {
		mScale = ofVec3f(fx, fy, fz);
	};

	virtual void apply() {
	};
	
	virtual void apply(std::shared_ptr<ofxParticle> p) {
	};

	void tick(double dt) {
		mTime += dt;
	}
	
	void setMinDistance(float distance) {
		mMinDistance = distance;
		mMinDistanceSq = distance*distance;
	}

	void setMaxDistance(float distance) {
		mMaxDistance = distance;
		mMaxDistanceSq = distance*distance;
	}

protected:
	ofxForce(float f) {
		mIsOn = true;
		setScale(f, f, f);
		mTime = 0;
		mMinDistance = 25;
		mMaxDistance = 100;
		mMinDistanceSq = mMinDistance*mMinDistance;
		mMaxDistanceSq = mMaxDistance*mMaxDistance;
		mVeryFarAway = 1000000000000000;
	};

	ofxForce(float fx, float fy, float fz) {
		mIsOn = true;
		setScale(fx, fy, fz);
		mTime = 0;
		mMinDistance = 25;
		mMaxDistance = 100;
		mMinDistanceSq = mMinDistance*mMinDistance;
		mMaxDistanceSq = mMaxDistance*mMaxDistance;
		mVeryFarAway = 1000000000000000;
	};

	ofVec3f mScale;
	bool mIsOn;
	double mTime;
	float mMinDistance;
	float mMinDistanceSq;
	float mMaxDistance;
	float mMaxDistanceSq;
	float mVeryFarAway;
};