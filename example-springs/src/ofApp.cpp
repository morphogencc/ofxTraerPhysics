#include "ofApp.h"
#include "ofxSpring.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("ofxTraerPhysics -- Spring Example");

	mParticleSystem = ofxTraerPhysics::ofxParticleSystem::make();

	mParticleA = mParticleSystem->addParticle(1.0, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0.0);
	mParticleB = mParticleSystem->addParticle(1.0, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0.0);


	std::shared_ptr<ofxTraerPhysics::ofxSpring> spring = ofxTraerPhysics::ofxSpring::make(mParticleA, mParticleB, 0.3, 0.1, 100.0);
	mParticleSystem->addSpring(spring);
}

//--------------------------------------------------------------
void ofApp::update(){
	mParticleSystem->tick();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofFill();
	ofSetColor(255, 0, 0);

	ofCircle(mParticleA->getPosition()[0], mParticleA->getPosition()[1], 5);
	ofCircle(mParticleB->getPosition()[0], mParticleB->getPosition()[1], 5);
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
