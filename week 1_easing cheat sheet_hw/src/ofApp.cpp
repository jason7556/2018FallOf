#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    posA.x = 100;
    posA.y = 100;
    
    posB.x = ofGetWidth()-150;
    posB.y = 100;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.006f;
    if (pct > 1) {
        pct = 0;
    }

    
    // linear
    
    r1 = ofMap(firstPos.x, 100, ofGetWidth()-150, 255, 0);
    
    firstPos.x = (1-pct) * posA.x + (pct) * posB.x;
    firstPos.y = (1-pct) * posA.y + (pct) * posB.y;
    
    
    // inQuint
    
    r2 = ofMap(secPos.x, 100, ofGetWidth()-150, 255, 0);
    
    float inQuintPct = inQuint(pct);
    secPos.x = (1-inQuintPct) * posA.x + (inQuintPct) * posB.x;
    secPos.y = (1-inQuintPct) * posA.y + (inQuintPct) * posB.y + 100;
    
    
    // outSine
    
    r3 = ofMap(thirdPos.x, 100, ofGetWidth()-150, 255, 0);
    
    float outSinePct = outSine(pct);
    thirdPos.x = (1-outSinePct) * posA.x + (outSinePct) * posB.x;
    thirdPos.y = (1-outSinePct) * posA.y + (outSinePct) * posB.y + 200;
    
    
    // inSine
    
    r4 = ofMap(fourthPos.x, 100, ofGetWidth()-150, 255, 0);
    
    float inSinePct = inSine(pct);
    fourthPos.x = (1-inSinePct) * posA.x + (inSinePct) * posB.x;
    fourthPos.y = (1-inSinePct) * posA.y + (inSinePct) * posB.y + 300;
    
    
    // outExpo
    
    r5 = ofMap(fifPos.x, 100, ofGetWidth()-150, 255, 0);
    
    float outExpoPct = outExpo(pct);
    fifPos.x = (1-outExpoPct) * posA.x + (outExpoPct) * posB.x;
    fifPos.y = (1-outExpoPct) * posA.y + (outExpoPct) * posB.y + 400;
    
    
    // outBounce
    
    r6 = ofMap(sixthPos.x, 100, ofGetWidth()-150, 255, 0);
    
    float outBouncePct = outBounce(pct);
    sixthPos.x = (1-outBouncePct) * posA.x + (outBouncePct) * posB.x;
    sixthPos.y = (1-outBouncePct) * posA.y + (outBouncePct) * posB.y + 500;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(r1);
    ofDrawRectangle(firstPos, 40,40);
    ofSetColor(r2);
    ofDrawRectangle(secPos,40,40);
    ofSetColor(r3);
    ofDrawRectangle(thirdPos,40,40);
    ofSetColor(r4);
    ofDrawRectangle(fourthPos,40,40);
    ofSetColor(r5);
    ofDrawRectangle(fifPos,40,40);
    ofSetColor(r6);
    ofDrawRectangle(sixthPos, 40, 40);
}

//--------------------------------------------------------------
float ofApp::inQuint(float t){
    return t * t * t * t * t;
}

//--------------------------------------------------------------
float ofApp::outSine(float t){
    return sin(t / 1 * (PI * 0.5));
}

//--------------------------------------------------------------
float ofApp::inSine(float t){
    return -1 * cos(t / 1 * (PI * 0.5)) + 1;
}

//--------------------------------------------------------------
float ofApp::outExpo(float t){
    return (t == 1) ? 1 : (-pow(2, -10 * t) + 1);
}

//--------------------------------------------------------------
float ofApp::outBounce(float t){
    if ((t /= 1) < (1 / 2.75)) {
        return (7.5625 * t * t);
    } else if (t < (2 / 2.75)) {
        return (7.5625 * (t -= (1.5 / 2.75)) * t + .75);
    } else if (t < (2.5 / 2.75)) {
        return (7.5625 * (t -= (2.25 / 2.75)) * t + .9375);
    } else {
        return (7.5625 * (t -= (2.625 / 2.75)) * t + .984375);
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
