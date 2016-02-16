#include "ofxSpring.h"

using namespace ofxTraerPhysics;

std::shared_ptr<ofxSpring> ofxSpring::make(std::shared_ptr<ofxParticle> particleA, std::shared_ptr<ofxParticle> particleB, float spring_constant, float dampening, float length) {
	std::shared_ptr<ofxSpring> spring(new ofxSpring(particleA, particleB, spring_constant, dampening, length));
	return spring;
}

std::shared_ptr<ofxParticle> ofxSpring::getEnd() {
	return mParticle;
}

std::shared_ptr<ofxParticle> ofxSpring::getOtherEnd() {
	return mOtherParticle;
}

float ofxSpring::getCurrentLength() {
	return mParticle->getPosition().distance(mOtherParticle->getPosition());
}

float ofxSpring::getRestLength() {
	return mRestLength;
}

float ofxSpring::getSpringConstant() {
	return mSpringConstant;
}

float ofxSpring::getDampeningConstant() {
	return mDampening;
}

void ofxSpring::setLength(float length) {
	mRestLength = length;
}

void ofxSpring::setSpringConstant(float k) {
	mSpringConstant = k;
}

void ofxSpring::setDampening(float d) {
	mDampening = d;
}

void ofxSpring::setParticle(std::shared_ptr<ofxParticle> particle) {
	mParticle = particle;
}

void ofxSpring::setOtherParticle(std::shared_ptr<ofxParticle> particle) {
	mOtherParticle = particle;
}

void ofxSpring::apply() {
	if (isOn() && (mParticle->isFree() || mOtherParticle->isFree())) {
		ofVec3f direction = mParticle->getPosition() - mOtherParticle->getPosition();
		direction.normalize();
		float distance = mParticle->getPosition().distance(mOtherParticle->getPosition());
		float springMagnitude = -mSpringConstant*(distance - mRestLength);
		ofVec3f springForce = direction * springMagnitude;

		ofVec3f diffVelocity = mParticle->getVelocity() - mOtherParticle->getVelocity();
		diffVelocity.normalize();
		float dampeningMagnitude = -mDampening*diffVelocity.dot(direction);
		ofVec3f dampeningForce = dampeningMagnitude*diffVelocity;

		ofVec3f totalForce = springForce + dampeningForce;
		mParticle->addForce(totalForce);
		mOtherParticle->addForce(-totalForce);
	}
}

ofxSpring::ofxSpring(std::shared_ptr<ofxParticle> particleA, std::shared_ptr<ofxParticle> particleB, float spring_constant, float dampening, float length) : ofxForce(1.0) {
	mParticle = particleA;
	mOtherParticle = particleB;
	mRestLength = length;
	mSpringConstant = spring_constant;
	mDampening = dampening;
}