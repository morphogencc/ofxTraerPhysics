#pragma once

#include <memory>

class ofxParticleSystem;

class ofxIntegrator {
public:
	ofxIntegrator(ofxParticleSystem* particleSystem) {
		mParticleSystem = particleSystem;
	};
	virtual ~ofxIntegrator() {};
	virtual void tick(float dt) {};
protected:
  ofxParticleSystem* mParticleSystem;
};