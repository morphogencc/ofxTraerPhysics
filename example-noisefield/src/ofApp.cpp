#include "ofApp.h"
#include "ofxPerlinForce.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("ofxTraerPhysics -- Noise Field Example");

	mParticleSystem = ofxTraerPhysics::ofxParticleSystem::make();
	mParticleSystem->setBoundaryConditions(ofxTraerPhysics::ofxParticleSystem::BoundaryType::PERIODIC, 0, ofGetWidth(), 0, ofGetHeight());

	for (int i = 0; i < 100; i++) {
		mParticleSystem->addParticle(ofRandom(1.0, 10.0), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	}

	std::shared_ptr<ofxTraerPhysics::ofxPerlinForce> noiseForce = ofxTraerPhysics::ofxPerlinForce::make(5.0);
	mParticleSystem->addForce(noiseForce);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofFill();

	mParticleSystem->tick(1.0);

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
