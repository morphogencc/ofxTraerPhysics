#pragma once

#include "ofxForce.h"
#include "ofxParticleSystem.h"

namespace ofxTraerPhysics {

	class ofxAlignmentForce : public ofxForce {
	public:
		static std::shared_ptr<ofxAlignmentForce> make(std::shared_ptr<ofxParticleSystem> particleSystem, float f);
		static std::shared_ptr<ofxAlignmentForce> make(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz);
		~ofxAlignmentForce();
		void setNeighborDistance(float distance);
		float getNeighborDistance();
		void apply(std::shared_ptr<ofxParticle> p);
	protected:
		ofxAlignmentForce(std::shared_ptr<ofxParticleSystem> particleSystem, float f);
		ofxAlignmentForce(std::shared_ptr<ofxParticleSystem> particleSystem, float fx, float fy, float fz);
		std::shared_ptr<ofxParticleSystem> mParticleSystem;
		float mNeighborDistance;
	};

}
