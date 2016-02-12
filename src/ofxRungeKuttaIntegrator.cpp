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
		if (!p->isFree()) {
			ofVec3f force = p->getForces();
			ofVec3f velocity = p->getVelocity();
			ofVec3f position = p->getPosition();

			//update position with last frame's velocity
			position += velocity*dt;

			//update velocity
			force *= dt / p->getMass();
			velocity += force;

			p->setVelocity(velocity);
			p->setPosition(position);
		}
	}
}


