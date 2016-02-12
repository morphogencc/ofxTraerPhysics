#include "ofxPropForce.h"

using namespace ofxTraerPhysics;

ofxPropForce::ofxPropForce(float f) : ofxForce(f) {

}

ofxPropForce::ofxPropForce(float fx, float fy, float fz) : ofxForce(fx, fy, fz) {

}

ofxPropForce::~ofxPropForce() {

}

void ofxPropForce::apply(std::shared_ptr<ofxParticle> p) {
	if (isOn()) {
		ofVec3f velocity = p->getVelocity();
		velocity[0] *= mScale[0];
		velocity[1] *= mScale[1];
		velocity[2] *= mScale[2];
		p->addForce(velocity);
	}
}
