#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofSetFullscreen(true);
    
    ofSetWindowShape(1280, 900);
    ofBackground(40);
    
    counter = 0;
    
    
    
    gui.setup();
    gui.add(r.setup("Redness",0,0,255) );
    gui.add(w.setup("Resolution",10,10,200) );
    gui.add(speed.setup("Speed",0.01,0.01,0.2) );
    gui.add(height.setup("Dynamic",10,10,800) );
    

    
    
//    w = 24;
    
    ma = atan(1/sqrt(2));
    
    maxD = ofDist(0,0,200,200);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    angle += speed;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();

    
    ofTranslate(0,0, -500);
//    cam.enableOrtho();
//    ofRotateX(-PI/4);
//    ofRotateY(ma);
    
    for (int z=  0 ; z< ofGetHeight() ; z+=w){
        for (int x=  0 ; x< ofGetWidth() ; x+=w){
        
            ofPushMatrix();
            ofTranslate( x-ofGetWidth()/2 , 0 ,  z - ofGetHeight()/2 );
    
            float d = ofDist(x,z,ofGetWidth()/2, ofGetHeight()/2);
            float offset = ofMap(d, 0, maxD, -2, 2);
            float a = angle + offset;
            float h = floor(ofMap(sin(a), -1, 1, 100, height));
            
//            r = 100;
            g = ofMap(offset, -2, 2, 70, 150);
            b = ofMap(h, 100, 300, 70, 180);
            

            ofSetColor(r,g,b);
            
            ofDrawBox( w-5 , h , w-5 );
//          ofDrawRectangle(x - ofGetWidth()/2 + w/2, 0, w-2, h);
        
            
            ofPopMatrix();
        
        }
    }
    
    
    
    cam.end();
    
    gui.draw();

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
