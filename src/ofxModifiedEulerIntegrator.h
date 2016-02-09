#pragma once

#include "ofxIntegrator.h"
#include "ofxParticleSystem.h"

namespace ofxTraerPhysics {

	class ofxModifiedEulerIntegrator : public ofxIntegrator {
	public:
		ofxModifiedEulerIntegrator(ofxParticleSystem* particleSystem);
		~ofxModifiedEulerIntegrator();
		void tick(float dt);
	protected:

	};

}