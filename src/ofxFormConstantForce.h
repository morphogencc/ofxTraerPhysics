#include "ofxForce.h"

class ofxFormConstantForce : public ofxForce {
public:
	ofxFormConstantForce(float f);
	ofxFormConstantForce(float fx, float fy, float fz);
	~ofxFormConstantForce();
	void apply(std::shared_ptr<ofxParticle> p);
	void horizontalBandsOn(int numBands);
	void horizontalBandsOff();
	void verticalBandsOn(int numBands);
	void verticalBandsOff();
	void armsOn(int numArms);
	void armsOff();
	void ringsOn(int numRings);
	void ringsOff();
protected:
	bool mVerticalBands;
	bool mHorizontalBands;
	bool mArms;
	bool mRings;
	int mNumVerticalBands;
	int mNumHorizontalBands;
	int mNumArms;
	int mNumRings;

	float mSpeed;
};