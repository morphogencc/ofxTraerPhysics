#include "ofxForce.h"
#include "Perlin.h"

class ofxPerlinForce : public ofxForce {
public:
	static std::shared_ptr<ofxPerlinForce> make(float f);
	static std::shared_ptr<ofxPerlinForce> make(float fx, float fy, float fz);
	~ofxPerlinForce();
	void apply(std::shared_ptr<ofxParticle> p);
protected:
	ofxPerlinForce(float f);
	ofxPerlinForce(float fx, float fy, float fz);
	Perlin* mNoise;
};