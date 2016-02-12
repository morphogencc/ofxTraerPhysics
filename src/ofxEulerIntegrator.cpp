#include "ofxEulerIntegrator.h"

using namespace ofxTraerPhysics;

ofxEulerIntegrator::ofxEulerIntegrator(ofxParticleSystem* particleSystem) : ofxIntegrator(particleSystem) {
};

ofxEulerIntegrator::~ofxEulerIntegrator() {
};

void ofxEulerIntegrator::tick(float dt) {
  mParticleSystem->clearForces();
  mParticleSystem->applyForces();

  for(auto p : mParticleSystem->getParticles()) {
    if(p->isFree()) {
		ofVec3f force = p->getForces();
		ofVec3f velocity = p->getVelocity();
		ofVec3f position = p->getPosition();
		
		force *= dt / (p->getMass());
		velocity += force;

		position += velocity * dt;

		p->setVelocity(velocity);
		p->setPosition(position);
    }
  }
}


