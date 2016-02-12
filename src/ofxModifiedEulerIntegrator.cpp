#include "ofxModifiedEulerIntegrator.h"

using namespace ofxTraerPhysics;

ofxModifiedEulerIntegrator::ofxModifiedEulerIntegrator(ofxParticleSystem* particleSystem) : ofxIntegrator(particleSystem) {
};

ofxModifiedEulerIntegrator::~ofxModifiedEulerIntegrator() {
};

void ofxModifiedEulerIntegrator::tick(float dt) {
	mParticleSystem->clearForces();
	mParticleSystem->applyForces();

	float tt = 0.5*dt*dt;

	for (auto p : mParticleSystem->getParticles()) {
		if (!p->isFree()) {
			ofVec3f force = p->getForces();
			ofVec3f velocity = p->getVelocity();
			ofVec3f position = p->getPosition();

			ofVec3f acceleration = force * 1.0 / p->getMass();

			position += velocity / dt;
			position += acceleration * tt;

			velocity += acceleration / dt;

			p->setVelocity(velocity);
			p->setPosition(position);
		}
	}
}


