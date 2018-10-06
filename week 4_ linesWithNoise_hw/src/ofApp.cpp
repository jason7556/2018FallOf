#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    
    noise = 0;
    
    gui.setup("Lines");
    gui.add(thickness.set("Thickness", 0.1f , 0.01f , 10.0f) );


}

//--------------------------------------------------------------
void ofApp::update(){
    
    noise +=0.1;
    
    for (auto &vert : line.getVertices()){
        vert.x += ofRandom(-2,2);
        vert.y += ofRandom(-2,2);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
//    camera.begin();
    ofSetLineWidth(thickness);
    ofSetColor(ofRandom(100,255), ofRandom(100,255), ofRandom(100,255));
    line.draw();
    
//    camera.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){

    line.clear();
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
    
    pt.set(x,y);
    
    line.addVertex(pt);

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
