#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("ofxTraerPhysics -- Attractor Example");

	mParticleSystem = ofxParticleSystem::make();
	mParticleSystem->setBoundaryConditions(ofxParticleSystem::BoundaryType::PERIODIC, 0, ofGetWidth(), 0, ofGetHeight());
	mParticleSystem->setGravity(0.2);

	for (int i = 0; i < 500; i++) {
		mParticleSystem->addParticle(1.0, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	}

	mAttractor = ofxAttractorForce::make(1000.0);
	mAttractor->setMinDistance(25.0);
	mParticleSystem->addForce(mAttractor);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofFill();

	mParticleSystem->tick(1.0);

	//draw attractor
	ofSetColor(128, 255, 0);
	mAttractor->setPosition(ofGetMouseX(), ofGetMouseY(), 0.0);
	ofCircle(mAttractor->getPosition()[0], mAttractor->getPosition()[1], 10);

	//draw particles
	ofSetColor(0, 255, 255);
	for (auto particle : mParticleSystem->getParticles()) {
		ofCircle(particle->getPosition()[0], particle->getPosition()[1], 5);
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
