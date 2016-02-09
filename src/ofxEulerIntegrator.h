#pragma once

#include "ofxIntegrator.h"
#include "ofxParticleSystem.h"

namespace ofxTraerPhysics {

	class ofxEulerIntegrator : public ofxIntegrator {
	public:
		ofxEulerIntegrator(ofxParticleSystem* particleSystem);
		~ofxEulerIntegrator();
		void tick(float dt);
	protected:

	};

}