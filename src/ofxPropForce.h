#include "ofxForce.h"

class ofxPropForce : public ofxForce {
public:
	ofxPropForce(float f);
	ofxPropForce(float fx, float fy, float fz);
	~ofxPropForce();
	void apply(std::shared_ptr<ofxParticle> p);
protected:
};