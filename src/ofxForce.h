#pragma once

#include "ofxParticle.h"

class ofxForce {
public:
	ofxForce(float f) {
		mIsOn = true;
		setScale(f, f, f);
		mTime = 0;
	};

	ofxForce(float fx, float fy, float fz) {
		mIsOn = true;
		setScale(fx, fy, fz);
		mTime = 0;
	};

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
		mScale = pfVec3(fx, fy, fz);
	};

	virtual void apply() {
	};
	
	virtual void apply(std::shared_ptr<ofxParticle> p) {
	};

	void tick(double t) {
		mTime = t;
	}

protected:
	pfVec3 mScale;
	bool mIsOn;
	double mTime;
};