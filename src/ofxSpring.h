#pragma once

#include "ofxForce.h"

class ofxSpring : public ofxForce {
public:
	static std::shared_ptr<ofxSpring> make(std::shared_ptr<ofxParticle> particleA, std::shared_ptr<ofxParticle> particleB, float spring_constant, float dampening, float length);
	std::shared_ptr<ofxParticle> getEnd();
	std::shared_ptr<ofxParticle> getOtherEnd();
	float getCurrentLength();
	float getRestLength();
	float getSpringConstant();
	float getDampeningConstant();
	void setLength(float length);
	void setSpringConstant(float k);
	void setDampening(float d);
	void setParticle(std::shared_ptr<ofxParticle> particle);
	void setOtherParticle(std::shared_ptr<ofxParticle> particle);
	void apply();
protected:
	ofxSpring(std::shared_ptr<ofxParticle> particleA, std::shared_ptr<ofxParticle> particleB, float spring_constant, float dampening, float length);
	float mRestLength;
	float mDampening;
	float mSpringConstant;
	std::shared_ptr<ofxParticle> mParticle;
	std::shared_ptr<ofxParticle> mOtherParticle;
};