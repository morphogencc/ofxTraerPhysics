
#include "ofxParticle.h"

std::shared_ptr<ofxParticle> ofxParticle::make(float mass = 1) {
	std::shared_ptr<ofxParticle> particle(new ofxParticle(mass));
	return particle;
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

ofVec3f ofxParticle::getPosition() {
	return mPosition;
}

ofVec3f ofxParticle::getVelocity() {
	return mVelocity;
}

ofVec3f ofxParticle::getForces() {
	return mForces;
}

void ofxParticle::setPosition(float x, float y, float z) {
	mPosition = ofVec3f(x, y, z);
}

void ofxParticle::setPosition(ofVec3f position) {
	mPosition.set(position);
}

void ofxParticle::setVelocity(ofVec3f velocity) {
	mVelocity.set(velocity);
}

void ofxParticle::addForce(ofVec3f force) {
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
	mPosition = ofVec3f(0, 0, 0);
	mVelocity = ofVec3f(0, 0, 0);
	mForces = ofVec3f(0, 0, 0);
	mMass = 1;
	mAge = 0;
	mAlive = true;
	mFree = true;
}

void ofxParticle::clearForces() {
	mForces = ofVec3f(0, 0, 0);
}

void ofxParticle::update(double t) {
	if (mAge > 0) {
		mAge--;
	}
}

ofxParticle::ofxParticle(float mass = 1) {
	mPosition = ofVec3f(0, 0, 0);
	mVelocity = ofVec3f(0, 0, 0);
	mForces = ofVec3f(0, 0, 0);
	mMass = mass;
	mAge = -1;
	mAlive = true;
	mFree = true;
}