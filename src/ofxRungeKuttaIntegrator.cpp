#include "stdafx.h"
#include "ofxRungeKuttaIntegrator.h"

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
			pfVec3 force = p.get()->getForces();
			pfVec3 velocity = p.get()->getVelocity();
			pfVec3 position = p.get()->getPosition();

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


