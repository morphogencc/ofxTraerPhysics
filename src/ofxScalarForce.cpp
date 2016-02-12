#include "ofxScalarForce.h"

using namespace ofxTraerPhysics;

ofxScalarForce::ofxScalarForce(float f) : ofxForce(f) {

}

ofxScalarForce::ofxScalarForce(float fx, float fy, float fz) : ofxForce(fx, fy, fz) {

}

ofxScalarForce::~ofxScalarForce() {

}

void ofxScalarForce::apply(std::shared_ptr<ofxParticle> p) {
	if (isOn()) {
		p->addForce(mScale);
	}
}
