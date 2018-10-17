#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(54, 54, 54);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

    
    soundStream.printDeviceList();
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter    = 0;
//    drawCounter        = 0;
    smoothedVol     = 0.0;
    scaledVol        = 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    scl = 20;
    
    cols = ofGetWidth()/scl;
    rows = ofGetHeight()/scl;
    
    counter = 0;
    
    

//    for (int x = 0; x < cols; x++) {
//        terrain[x] = [];
//        for (int y = 0; y < rows; y++) {
//            terrain[x][y] = 0; //specify a default value for now
//        }
//    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    counter += 0.01;

    
//    flying -= 0.1;
//    float yoff = flying;
//    for (int y = 0; y < rows; y++) {
//        float xoff = 0;
//        for (int x = 0; x < cols; x++) {
//            terrain[x][y] = ofMap(ofNoise(xoff, yoff), 0, 1, -100, 100);
//            xoff += 0.2;
//        }
//        yoff += 0.2;
//    }
    
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    cam.begin();

    
//    ofSetColor(245, 58, 135);
//    ofNoFill();
//    ofDrawSphere(ballX, 300, 80);

    
    ofNoFill();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateX(60);
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    ofBeginShape();

    for (int y=0 ; y<rows ; y++){
        for (int x=0 ; x<cols ; x++){
            ofVertex(x*scl, y*scl, ofRandom(scaledVol*300)*ofNoise(counter) );
            ofVertex(x*scl, (y+1)*scl, ofRandom(scaledVol*500) * ofNoise(counter) );
        }
    }
    ofEndShape();

    
    
//    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]        = input[i*2]*0.5;
        right[i]    = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;

    
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
