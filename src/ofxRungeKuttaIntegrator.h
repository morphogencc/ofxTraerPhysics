#pragma once

#include "ofxIntegrator.h"
#include "ofxParticleSystem.h"

class ofxRungeKuttaIntegrator : public ofxIntegrator {
public:
	ofxRungeKuttaIntegrator(ofxParticleSystem* particleSystem);
	~ofxRungeKuttaIntegrator();
	void tick(float dt);
protected:

};
