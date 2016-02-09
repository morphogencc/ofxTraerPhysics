#include "ofxRungeKuttaIntegrator.h"

using namespace ofxTraerPhysics;

ofxRungeKuttaIntegrator::ofxRungeKuttaIntegrator(ofxParticleSystem* particleSystem) : ofxIntegrator(particleSystem) {
};

ofxRungeKuttaIntegrator::~ofxRungeKuttaIntegrator() {
};

void ofxRungeKuttaIntegrator::tick(float dt) {
	/* CURRENTLY STILL EULER -- NEEDS TO BE FIXED */
	mParticleSystem->clearForces();
	mParticleSystem->applyForces();

	for (auto p : mParticleSystem->getParticles()) {
		if (!p.get()->isFree()) {
			ofVec3f force = p.get()->getForces();
			ofVec3f velocity = p.get()->getVelocity();
			ofVec3f position = p.get()->getPosition();

			//update position with last frame's velocity
			position += velocity*dt;

			//update velocity
			force *= dt / p.get()->getMass();
			velocity += force;

			p.get()->setVelocity(velocity);
			p.get()->setPosition(position);
		}
	}
}


