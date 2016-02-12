#include "ofApp.h"
#include "ofxAlignmentForce.h"
#include "ofxCohesiveForce.h"
#include "ofxSeparateForce.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("ofxTraerPhysics -- Flocking Example");
	mParticleSystem = ofxTraerPhysics::ofxParticleSystem::make();
	mParticleSystem->setBoundaryConditions(ofxTraerPhysics::ofxParticleSystem::BoundaryType::PERIODIC, 0, ofGetWidth(), 0, ofGetHeight());

	std::shared_ptr<ofxTraerPhysics::ofxAlignmentForce> alignmentForce = ofxTraerPhysics::ofxAlignmentForce::make(mParticleSystem, 3.0);
	mParticleSystem->addForce(alignmentForce);

	std::shared_ptr<ofxTraerPhysics::ofxCohesiveForce> cohesiveForce = ofxTraerPhysics::ofxCohesiveForce::make(mParticleSystem, 5.0);
	mParticleSystem->addForce(cohesiveForce);

	std::shared_ptr<ofxTraerPhysics::ofxSeparateForce> separateForce = ofxTraerPhysics::ofxSeparateForce::make(mParticleSystem, 10.0);
	mParticleSystem->addForce(separateForce);

	mSeekerForce = ofxTraerPhysics::ofxSeekerForce::make(20.0);
	mParticleSystem->addForce(mSeekerForce);


	for (int i = 0; i < 100; i++) {
		mParticleSystem->addParticle(1.0, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	mParticleSystem->tick(0.25);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofFill();

	ofSetColor(128, 255, 0);
	mSeekerForce->setTarget(ofVec3f(ofGetMouseX(), ofGetMouseY(), 0.0));
	ofCircle(mSeekerForce->getTarget()[0], mSeekerForce->getTarget()[1], 10);

	ofSetColor(0, 255, 255);
	for (auto particle : mParticleSystem->getParticles()) {
		ofCircle(particle->getPosition()[0], particle->getPosition()[1], 2);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
