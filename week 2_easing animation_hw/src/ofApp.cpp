#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(40);
    ofSetWindowShape(1280, 900);

    
    for (int i=0 ; i<16000 ; i++){
        
        Particle newParticle;
        newParticle.reset();
        particles.push_back( newParticle );
        
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    for (int i=0 ; i<particles.size() ; i++){
        particles[i].update(mouse);
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    for (int i=0 ; i<particles.size() ; i++){
        particles[i].draw();
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
    
    mouse.x = x;
    mouse.y = y;

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
