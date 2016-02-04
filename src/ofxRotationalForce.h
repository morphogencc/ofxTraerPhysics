#include "ofxForce.h"

class ofxRotationalForce : public ofxForce {
public:
	ofxRotationalForce(float f);
	~ofxRotationalForce();
	void apply(std::shared_ptr<ofxParticle> p);
	pfVec3 getPosition();
	void setPosition(float x, float y, float z);
	void setMinDistance(float distance);
	void setMaxDistance(float distance);
protected:
	pfVec3 mPosition;
	float mMinDistance;
	float mMaxDistance;
	float mVeryFarAway;
};