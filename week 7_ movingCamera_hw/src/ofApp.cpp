#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableDepthTest();
    ofSetBackgroundColor(0);
    ofSetFullscreen(true);
    
    for(int i =0; i<2500; i++){
        boxPos.set(ofRandom(-5000,5000), ofRandom(-5000,5000),ofRandom(-5000,5000));
        boxes.push_back(boxPos);
        
    }
    
//    light.setPosition(10,150,10);
//    light.setAmbientColor(ofFloatColor(.1,.1,.1));
//    light.enable();
    
    color.set(255);
    cam.setPosition(100,50,100);
    
    folloPos.set(250,250,250);
    
    counter = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    counter += .0009;

    
//    for(int i =0; i<200; i++){
//
//        float x = ofNoise(counter, i * .005) * ofGetWidth();
//        float y = ofNoise(i * .005, counter) * ofGetHeight();
//        float z = ofNoise(i * .005, counter) * 200;
//
//
//        boxPos.x = x;
//        boxPos.y = y;
//        boxPos.z = z;
//
//    }
    
    
    if(count == true){
        if(pct<1)pct += 0.0015;
        float mPct1 = inOutSine(pct);
        float nPct1 = inQuad(pct);
        
        folloPos = (1-mPct1) * folloPos + mPct1 * boxes[lookAtMe] ;
        cam.lookAt(folloPos);
        
        
        desPos = boxes[lookAtMe]+100;
        camPos = (1-nPct1) * camPos + nPct1 * desPos * ofNoise(counter);
        prePos = camPos;
        cam.setPosition(camPos);
       
        
    }

    
    ofLog()<<pct;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    for(int i =0; i<boxes.size();i++){
        ofSetColor(255);
        ofDrawSphere(boxes[i], 10);
        ofSetColor(0,0, ofNoise(counter*25)*450);
        ofDrawSphere(boxes[lookAtMe], 20);
    }
    
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //    cameraTurn();
    cameraMoves();
    count = true;
    
}

float ofApp::inOutSine(float t){
    return 0.5 * (1+sin(PI*(t-0.5)));
}

float ofApp::inQuad(float t){
    return t * t;
}

//--------------------------------------------------------------
void ofApp::cameraMoves(){
    
//    color.set(0,0, ofNoise(counter*10)*800);
    pct = 0;
    
    lookAtMe = ofRandom(2500);
    
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
