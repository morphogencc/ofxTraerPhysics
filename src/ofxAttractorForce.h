#include "ofxForce.h"

class ofxAttractorForce : public ofxForce {
public:
	static std::shared_ptr<ofxAttractorForce> make(float f);
	static std::shared_ptr<ofxAttractorForce> make(float fx, float fy, float fz);
	~ofxAttractorForce();
	void apply(std::shared_ptr<ofxParticle> p);
	ofVec3f getPosition();
	void setPosition(float x, float y, float z);
protected:
	ofxAttractorForce(float f);
	ofxAttractorForce(float fx, float fy, float fz);
	ofVec3f mPosition;
};