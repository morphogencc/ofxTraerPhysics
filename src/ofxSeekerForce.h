#pragma once

#include "ofxForce.h"
#include "ofxParticleSystem.h"

namespace ofxTraerPhysics {

	class ofxSeekerForce : public ofxForce {
	public:
		static std::shared_ptr<ofxSeekerForce> make(float f);
		static std::shared_ptr<ofxSeekerForce> make(float fx, float fy, float fz);
		~ofxSeekerForce();
		void setTarget(ofVec3f target);
		ofVec3f getTarget();
		void apply(std::shared_ptr<ofxParticle> p);
	protected:
		ofxSeekerForce(float f);
		ofxSeekerForce(float fx, float fy, float fz);
		ofVec3f mTarget;
	};

}
