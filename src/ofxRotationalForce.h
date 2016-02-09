#include "ofxForce.h"

namespace ofxTraerPhysics {

	class ofxRotationalForce : public ofxForce {
	public:
		ofxRotationalForce(float f);
		~ofxRotationalForce();
		void apply(std::shared_ptr<ofxParticle> p);
		ofVec3f getPosition();
		void setPosition(float x, float y, float z);
		void setMinDistance(float distance);
		void setMaxDistance(float distance);
	protected:
		ofVec3f mPosition;
		float mMinDistance;
		float mMaxDistance;
		float mVeryFarAway;
	};

}