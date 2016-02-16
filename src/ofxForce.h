#pragma once

#include "ofxParticle.h"

namespace ofxTraerPhysics {

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

		void setMinForce(float magnitude) {
			mMinForce = magnitude;
		}

		void setMaxForce(float magnitude) {
			mMaxForce = magnitude;
		}


	protected:
		ofxForce(float f) {
			mIsOn = true;
			setScale(f, f, f);
			mTime = 0;
			mMinForce = 0.1;
			mMaxForce = 1000;
		};

		ofxForce(float fx, float fy, float fz) : ofxForce(1.0) {
			setScale(fx, fy, fz);
		};

		float clampForce(float magnitude) {
			if (magnitude > mMaxForce) {
				return mMaxForce;
			}
			else if (magnitude < mMinForce) {
				return mMinForce;
			}
			else {
				return magnitude;
			}
		}

		ofVec3f mScale;
		bool mIsOn;
		double mTime;
		float mMinForce;
		float mMaxForce;
	};

}