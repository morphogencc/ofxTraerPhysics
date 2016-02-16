#pragma once

#include "ofxForce.h"
#include "ofxParticleSystem.h"

namespace ofxTraerPhysics {

	class ofxSeparateForce : public ofxForce {
	public:
		static std::shared_ptr<ofxSeparateForce> make(std::shared_ptr<ofxParticleSystem> particleSystem, float f);
		static std::shared_ptr<ofxSeparateForce> make(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz);
		~ofxSeparateForce();
		void setDesiredSeparation(float separation);
		float getDesiredSeparation();
		void apply(std::shared_ptr<ofxParticle> p);
	protected:
		ofxSeparateForce(std::shared_ptr<ofxParticleSystem> particleSystem, float f);
		ofxSeparateForce(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz);
		std::shared_ptr<ofxParticleSystem> mParticleSystem;
		float mDesiredSeparation;
	};

}
