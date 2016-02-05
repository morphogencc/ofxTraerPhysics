#pragma once

#include <memory>
#include "ofxParticle.h"
#include "ofxForce.h"
#include "ofxScalarForce.h"
#include "ofxPropForce.h"
#include "ofxIntegrator.h"

class ofxParticleSystem {
public:
	enum Integrator { EULER, MODIFIED_EULER, RUNGE_KUTTA };
	enum BoundaryType { NONE, BOX, PERIODIC };

	static std::shared_ptr<ofxParticleSystem> make();
	~ofxParticleSystem();

	void setIntegrator(Integrator method);
	void setBoundaryConditions(BoundaryType boundary, float minX, float maxX, float minY, float maxY);

	void setGravity(float g);
	void setGravity(float gx, float gy, float gz);

	void setDrag(float d);
	void setDrag(float dx, float dy, float dz);

	void addParticle(float m);
	void addParticle(float m, float x, float y);
	void addParticle(float m, float x, float y, float z);

	std::shared_ptr<ofxParticle> getParticle(int i);
	std::vector<std::shared_ptr<ofxParticle> > getParticles();
	int getNumberOfParticles();

	void applyForces();
	void clearForces();
	void addForce(std::shared_ptr<ofxForce> f);
	int getNumberOfForces();
	void clear();

	void tick();
	void tick(double dt);

protected:
	ofxParticleSystem();

	Integrator mIntegrationMethod;
	BoundaryType mBoundaryType;
	static const float DEFAULT_GRAVITY;
	static const float DEFAULT_DRAG;

	float mMinX;
	float mMaxX;
	float mMinY;
	float mMaxY;

	std::shared_ptr<ofxIntegrator> mIntegrator;
	std::shared_ptr<ofxScalarForce> mGravityForce;
	std::shared_ptr<ofxPropForce> mDragForce;

	std::vector<std::shared_ptr<ofxParticle> > mParticles;
	std::vector<std::shared_ptr<ofxForce> > mForces;

};
