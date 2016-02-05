
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
		ofVec3f force = p.get()->getForces();
		ofVec3f velocity = p.get()->getVelocity();
		ofVec3f position = p.get()->getPosition();
		
		force *= dt / (p.get()->getMass());
		velocity += force;

		position += velocity * dt;

		p.get()->setVelocity(velocity);
		p.get()->setPosition(position);
    }
  }
}


