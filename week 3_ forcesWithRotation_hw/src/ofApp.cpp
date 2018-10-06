#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofDisableAlphaBlending();
    
    
    for (int i=0 ; i< 50; i++){
        Pacman p;
        pacmans.push_back(p);
        pacmans[i].setup();
    }


}

//--------------------------------------------------------------
void ofApp::update(){
    
//    ofPoint mouseP = ofPoint(mousePressedX, MousePressedY);
    
    for (int i=0 ; i < pacmans.size() ; i++){
        pacmans[i].attraction(pacmans);
        pacmans[i].separation(pacmans);
        pacmans[i].follow(pacmans);
        
        pacmans[i].addAttractionForce(mouseP,200,0.005);
        pacmans[i].update();
    }
    
    for (int i=0 ; i< pacmans.size(); i++){
        for (int j=0 ; j< pacmans.size(); j++){
            pacmans[i].addRepulsionForce(pacmans[j].pos, 35, .8);
            pacmans[j].addRepulsionForce(pacmans[i].pos, 35, .8);
        }
    }
    
    for (int i = foddors.size()-1 ; i >= 0 ; i--) {
        foddors[i].update();
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(30);

    for (int i=0 ; i < pacmans.size() ; i++){
        pacmans[i].draw();
    }
    
    for (int i=0 ; i< foddors.size(); i++){
        foddors[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

    for (int i=0 ; i< pacmans.size(); i++){
        if (key == 'd'){
            pacmans[i].vel.x += 4;
        }
        if (key == 'a'){
            pacmans[i].vel.x -= 4;
        }
        if (key == 'w'){
            pacmans[i].vel.y -= 4;
        }
        if (key == 's'){
            pacmans[i].vel.y += 4;
        }
    }


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
    
    mouseP = ofPoint(x,y);
    
    for (int i=0 ; i< 1; i++){
        Foddor f;
        foddors.push_back(f);
        foddors[foddors.size()-1].setup(mouseP);
    }
    
//    Foddor f;
//
//    foddors.push_back(f);
//    f.pos = mouseP;

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
