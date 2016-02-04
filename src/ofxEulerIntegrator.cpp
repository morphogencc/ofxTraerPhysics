#include "stdafx.h"
#include "ofxEulerIntegrator.h"

ofxEulerIntegrator::ofxEulerIntegrator(ofxParticleSystem* particleSystem) : ofxIntegrator(particleSystem) {
};

ofxEulerIntegrator::~ofxEulerIntegrator() {
};

void ofxEulerIntegrator::tick(float dt) {
  mParticleSystem->clearForces();
  mParticleSystem->applyForces();

  for(auto p : mParticleSystem->getParticles()) {
    if(p.get()->isFree()) {
		pfVec3 force = p.get()->getForces();
		pfVec3 velocity = p.get()->getVelocity();
		pfVec3 position = p.get()->getPosition();
		
		force *= 1.0 / (p.get()->getMass()*dt);
		velocity += force;

		position += velocity / dt;

		p.get()->setVelocity(velocity);
		p.get()->setPosition(position);
    }
  }
}


