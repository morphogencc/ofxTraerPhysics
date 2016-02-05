
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
			ofVec3f force = p.get()->getForces();
			ofVec3f velocity = p.get()->getVelocity();
			ofVec3f position = p.get()->getPosition();

			ofVec3f acceleration = force * 1.0 / p.get()->getMass();

			position += velocity / dt;
			position += acceleration * tt;

			velocity += acceleration / dt;

			p.get()->setVelocity(velocity);
			p.get()->setPosition(position);
		}
	}
}


