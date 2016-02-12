#pragma once

#include "ofxForce.h"
#include "ofxParticleSystem.h"

namespace ofxTraerPhysics {

	class ofxCohesiveForce : public ofxForce {
	public:
		static std::shared_ptr<ofxCohesiveForce> make(std::shared_ptr<ofxParticleSystem> particleSystem, float f);
		static std::shared_ptr<ofxCohesiveForce> make(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz);
		~ofxCohesiveForce();
		void setNeighborDistance(float distance);
		float getNeighborDistance();
		void apply(std::shared_ptr<ofxParticle> p);
	protected:
		ofxCohesiveForce(std::shared_ptr<ofxParticleSystem> particleSystem, float f);
		ofxCohesiveForce(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz);
		std::shared_ptr<ofxParticleSystem> mParticleSystem;
		float mNeighborDistance;
	};

}
