#pragma once

#include "ofxIntegrator.h"
#include "ofxParticleSystem.h"

class ofxModifiedEulerIntegrator : public ofxIntegrator {
public:
	ofxModifiedEulerIntegrator(ofxParticleSystem* particleSystem);
	~ofxModifiedEulerIntegrator();
	void tick(float dt);
protected:

};
