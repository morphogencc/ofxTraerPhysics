#include "stdafx.h"
#include "ofxPerlinForce.h"

ofxPerlinForce::ofxPerlinForce(float f) : ofxForce(f) {
	mNoise = new Perlin(3, 2, 2, 0);
}

ofxPerlinForce::ofxPerlinForce(float fx, float fy, float fz) : ofxForce(fx, fy, fz) {

}

ofxPerlinForce::~ofxPerlinForce() {

}

void ofxPerlinForce::apply(std::shared_ptr<ofxParticle> p) {
	if (isOn()) {
		pfVec3 position = p.get()->getPosition();
		pfVec3 force;
		float vec[3];
		vec[0] = 0.001*position[0];
		vec[1] = 0.001*position[1];
		vec[2] = 0.1*mTime;
		
		float noiseValue = mNoise->perlin_noise_3D(vec);
		force[0] = mScale[0]*0.1*cos(noiseValue * 2.0 * 3.14159);
		force[1] = mScale[1]*0.1*sin(noiseValue * 2.0 * 3.14159);
		force[2] = 0;

		p->addForce(force);
	}
}
