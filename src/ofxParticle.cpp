#include "stdafx.h"
#include "ofxParticle.h"

ofxParticle::ofxParticle(float mass = 1) {
	mPosition = pfVec3(0, 0, 0);
	mVelocity = pfVec3(0, 0, 0);
	mForces = pfVec3(0, 0, 0);
	mMass = mass;
	mAge = -1;
	mAlive = true;
	mFree = true;

	mRandom = std::rand() % 120;
}

void ofxParticle::setMass(float mass) {
	mMass = mass;
}

void ofxParticle::makeFixed() {
	mFree = false;
}

void ofxParticle::makeFree() {
	mFree = true;
}

pfVec3 ofxParticle::getPosition() {
	return mPosition;
}

pfVec3 ofxParticle::getVelocity() {
	return mVelocity;
}

pfVec3 ofxParticle::getForces() {
	return mForces;
}

void ofxParticle::setPosition(float x, float y, float z) {
	mPosition = pfVec3(x, y, z);
	setTrans(mPosition);
}

void ofxParticle::setPosition(pfVec3 position) {
	mPosition = position;
	setTrans(mPosition);
}

void ofxParticle::setVelocity(pfVec3 velocity) {
	mVelocity = velocity;
}

void ofxParticle::addForce(pfVec3 force) {
	mForces += force;
}

float ofxParticle::getMass() {
	return mMass;
}

int ofxParticle::getAge() {
	return mAge;
}

void ofxParticle::setAge(int age) {
	mAge = age;
}

bool ofxParticle::isFree() {
	return mFree;
}

bool ofxParticle::isAlive() {
	return mAlive;
}

void ofxParticle::reset() {
	mPosition = pfVec3(0, 0, 0);
	mVelocity = pfVec3(0, 0, 0);
	mForces = pfVec3(0, 0, 0);
	mMass = 1;
	mAge = 0;
	mAlive = true;
	mFree = true;
}

void ofxParticle::clearForces() {
	mForces = pfVec3(0, 0, 0);
}

void ofxParticle::update(double t) {
	if (mAge > 0) {
		mAge--;
	}
}