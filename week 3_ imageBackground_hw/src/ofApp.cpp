#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofSetCircleResolution(60);
    ofBackground(30);
    
    webcam.initGrabber(640, 480);
    
    grayImage.allocate(640, 480);
    backgroundImage.allocate(640, 480);
    diffImage.allocate(640, 480);
    
    flowSolver.setup(640, 480, 0.35, 5, 10, 1, 3, 2.25, false, false);

    
    for (int i=0 ; i< 500; i++){

        Particle p;
        particles.push_back(p);
        particles[i].setup( ofPoint( ofRandom(ofGetWidth()) , ofRandom(ofGetHeight()) ) );
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    webcam.update();
    
    if(webcam.isFrameNew()) {
        flowSolver.update(webcam);
            for(auto& p : particles) {
                ofPoint flow = flowSolver.getVelAtPixel(p.pos.x, p.pos.y);
                p.vel += flow;
            }
        
        diffImage.absDiff(grayImage, backgroundImage);
        contours.findContours(diffImage, 5, (340*240)/4, 4, false, true);
    }
    
    
    
    ofPoint mouse = ofPoint(mouseX, mouseY);
    
    for (int i=0 ; i< particles.size(); i++){
        // find the 1d index of the x and y of the particle
        int x = int(ofMap(particles[i].pos.x,0,ofGetWidth(),0,640));
        int y = int(ofMap(particles[i].pos.y,0,ofGetWidth(),0,640));
        int index = x+y*webcam.getWidth();
        ofColor color = webcam.getPixels().getColor(x, y);
        particles[i].addAttractionForce(mouse,100,.1);
        particles[i].update(color);
//        for(int y=0; y<webcam.getHeight(); y+=30) {
//            for(int x=0; x<webcam.getWidth(); x+=30) {
//                int index = x+y*webcam.getWidth();
//                ofColor color = webcam.getPixels().getColor(x, y);
//                particles[i].update(color);
//            }
//        }
    }
    
    // particle to particle repulsion
    
    for (int i=0 ; i< particles.size(); i++){
        for (int j=0 ; j< particles.size(); j++){
            particles[i].addRepulsionForce(particles[j].pos, 35, .2);
            particles[j].addRepulsionForce(particles[i].pos, 35, .2);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0 ; i< particles.size(); i++){
        particles[i].draw();
    }
    
//    if(contours.blobs.size() > 0) {
//
//    ofSetColor(255);
//
//    }
    
//    for (int i=0 ; i<contours.nBlobs ; i++){
//        ofxCvBlob& blob = contours.blobs[i];
//        vector<ofPoint>& pts = blob.pts;
//            ofPoint centroid = contours.blobs[0].centroid;
//
//        for (int j=0 ; j<pts.size() ; j++){
//            ofSetColor(255);
//            ofDrawCircle(pts[j],1);
//            ofDrawCircle( centroid, 20 );
//
//        }
//    }
    

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
