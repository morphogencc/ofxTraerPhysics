#include "stdafx.h"
#include "ofxParticleSystem.h"
#include "ofxEulerIntegrator.h"
#include "ofxModifiedEulerIntegrator.h"
#include "ofxRungeKuttaIntegrator.h"

const float ofxParticleSystem::DEFAULT_GRAVITY = 0.0;
const float ofxParticleSystem::DEFAULT_DRAG = 0.05;
std::shared_ptr<ofxParticleSystem> ofxParticleSystem::mParticleSystem = nullptr;

std::shared_ptr<ofxParticleSystem> ofxParticleSystem::getInstance() {
	if (mParticleSystem == nullptr) {
		mParticleSystem = std::make_shared<ofxParticleSystem>();
}	
	return mParticleSystem;
}

ofxParticleSystem::ofxParticleSystem() {
	mIntegrationMethod = EULER;
	mBoundaryType = NONE;

	mMinX = 0;
	mMaxX = 0;
	mMinY = 0;
	mMaxY = 0;

	setIntegrator(mIntegrationMethod);

	mGravityForce = std::make_shared<ofxScalarForce>(0, DEFAULT_GRAVITY, 0);
	mForces.push_back(mGravityForce);

	mDragForce = std::make_shared<ofxPropForce>(-DEFAULT_DRAG, -DEFAULT_DRAG, -DEFAULT_DRAG);
	mForces.push_back(mDragForce);
}

ofxParticleSystem::~ofxParticleSystem() {

}

void ofxParticleSystem::setIntegrator(Integrator method) {
	switch (method) {
	case EULER:
		mIntegrator = std::make_shared<ofxEulerIntegrator>(this);
		break;
	case MODIFIED_EULER:
		mIntegrator = std::make_shared<ofxModifiedEulerIntegrator>(this);
		break;
	case RUNGE_KUTTA:
		mIntegrator = std::make_shared<ofxRungeKuttaIntegrator>(this);
		break;
	}
}

void ofxParticleSystem::setBoundaries(float minX, float maxX, float minY, float maxY) {
	mMinX = minX;
	mMaxX = maxX;
	mMinY = minY;
	mMaxY = maxY;
}

void ofxParticleSystem::setBoundaryType(BoundaryType boundary) {
	mBoundaryType = boundary;
}

void ofxParticleSystem::setGravity(float g) {
	mGravityForce = std::make_shared<ofxScalarForce>(0, g, 0);
}

void ofxParticleSystem::setGravity(float gx, float gy, float gz) {
	mGravityForce = std::make_shared<ofxScalarForce>(gx, gy, gz);
}

void ofxParticleSystem::setDrag(float d) {
	mDragForce = std::make_shared<ofxPropForce>(d, d, d);
}

void ofxParticleSystem::setDrag(float dx, float dy, float dz) {
	mDragForce = std::make_shared<ofxPropForce>(dx, dy, dz);
}

void ofxParticleSystem::addParticle(float m) {
	std::shared_ptr<ofxParticle> p = std::make_shared<ofxParticle>(m);
	p.get()->setPosition(0, 0, 0);
	mParticles.push_back(p);
	addChild(p.get());
}

void ofxParticleSystem::addParticle(float m, float x, float y) {
	std::shared_ptr<ofxParticle> p = std::make_shared<ofxParticle>(m);
	p.get()->setPosition(x, y, 0);
	mParticles.push_back(p);
	addChild(p.get());
}

void ofxParticleSystem::addParticle(float m, float x, float y, float z) {
	std::shared_ptr<ofxParticle> p = std::make_shared<ofxParticle>(m);
	p.get()->setPosition(x, y, z);
	mParticles.push_back(p);
	addChild(p.get());
}

int ofxParticleSystem::getNumberOfParticles() {
	return mParticles.size();
}

std::shared_ptr<ofxParticle> ofxParticleSystem::getParticle(int i) {
	return mParticles.at(i);
}

std::vector<std::shared_ptr<ofxParticle> > ofxParticleSystem::getParticles() {
	return mParticles;
}

void ofxParticleSystem::applyForces() {
	for (auto f : mForces) {
		for (auto p : mParticles) {
			f.get()->apply(p);
		}
	}
}

void ofxParticleSystem::clearForces() {
	for (auto p : mParticles) {
		p.get()->clearForces();
	}
}

void ofxParticleSystem::addForce(std::shared_ptr<ofxForce> f) {
	mForces.push_back(f);
}

int ofxParticleSystem::getNumberOfForces() {
	return mForces.size();
}

void ofxParticleSystem::clear() {
	mParticles.clear();
	mForces.clear();
}

void ofxParticleSystem::update(double t) {
	mIntegrator.get()->tick(1);

	//update time-dependent forces
	for (auto f : mForces) {
		f.get()->tick(t);
	}

	if (mBoundaryType == BoundaryType::BOX) {
		for (auto p : mParticles) {
			ofVec3f position = p.get()->getPosition();
			ofVec3f velocity = p.get()->getVelocity();
			if (position[0] < mMinX) {
				velocity[0] *= -1;
			}
			else if (position[0] > mMaxX) {
				velocity[0] *= -1;
			}
			if (position[1] < mMinY) {
				velocity[1] *= -1;
			}
			else if (position[1] > mMaxY) {
				velocity[1] *= -1;
			}
			p->setVelocity(velocity);
		}
	}
	else if (mBoundaryType == BoundaryType::PERIODIC) {
		for (auto p : mParticles) {
			ofVec3f position = p.get()->getPosition();
			if (position[0] < mMinX) {
				position[0] = mMaxX;
			}
			else if (position[0] > mMaxX) {
				position[0] = mMinX;
			}
			if (position[1] < mMinY) {
				position[1] = mMaxY;
			}
			else if (position[1] > mMaxY) {
				position[1] = mMinY;
			}
			p->setPosition(position);

		}
	}
	
	else if (mBoundaryType == BoundaryType::NONE) {

	}
}