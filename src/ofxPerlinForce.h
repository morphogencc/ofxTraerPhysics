#include "ofxForce.h"
#include "Perlin.h"

class ofxPerlinForce : public ofxForce {
public:
	ofxPerlinForce(float f);
	ofxPerlinForce(float fx, float fy, float fz);
	~ofxPerlinForce();
	void apply(std::shared_ptr<ofxParticle> p);
protected:
	Perlin* mNoise;
};