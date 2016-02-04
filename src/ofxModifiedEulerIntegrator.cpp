#include "stdafx.h"
#include "ofxModifiedEulerIntegrator.h"

ofxModifiedEulerIntegrator::ofxModifiedEulerIntegrator(ofxParticleSystem* particleSystem) : ofxIntegrator(particleSystem) {
};

ofxModifiedEulerIntegrator::~ofxModifiedEulerIntegrator() {
};

void ofxModifiedEulerIntegrator::tick(float dt) {
	mParticleSystem->clearForces();
	mParticleSystem->applyForces();

	float tt = 0.5*dt*dt;

	for (auto p : mParticleSystem->getParticles()) {
		if (!p.get()->isFree()) {
			pfVec3 force = p.get()->getForces();
			pfVec3 velocity = p.get()->getVelocity();
			pfVec3 position = p.get()->getPosition();

			pfVec3 acceleration = force * 1.0 / p.get()->getMass();

			position += velocity / dt;
			position += acceleration * tt;

			velocity += acceleration / dt;

			p.get()->setVelocity(velocity);
			p.get()->setPosition(position);
		}
	}
}


