#pragma once

#include "ofMain.h"

namespace ofxTraerPhysics {

	class ofxParticle {
	public:
		static std::shared_ptr<ofxParticle> make(float mass);
		static std::shared_ptr<ofxParticle> make(float mass, float x, float y, float z);
		static std::shared_ptr<ofxParticle> make(float mass, ofVec3f position);
		void update(double t);
		void setMass(float mass);
		void makeFixed();
		void makeFree();
		ofVec3f getPosition();
		ofVec3f getVelocity();
		ofVec3f getForces();
		void setPosition(float x, float y, float z);
		void setPosition(ofVec3f position);
		void setVelocity(ofVec3f velocity);
		void addForce(ofVec3f force);
		float getMass();
		int getAge();
		void setAge(int age);
		bool isFree();
		bool isAlive();
		void reset();
		void clearForces();
	protected:
		ofxParticle(float mass);
		ofVec3f mPosition;
		ofVec3f mVelocity;
		ofVec3f mForces;
		float mMass;
		int mAge;
		bool mAlive;
		bool mFree;
	};

}