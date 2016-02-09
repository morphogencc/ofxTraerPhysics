#include "ofxForce.h"

namespace ofxTraerPhysics {

	class ofxScalarForce : public ofxForce {
	public:
		ofxScalarForce(float f);
		ofxScalarForce(float fx, float fy, float fz);
		~ofxScalarForce();
		void apply(std::shared_ptr<ofxParticle> p);
	protected:
	};

}
