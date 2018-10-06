#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(40,40,40);
    ofSetFullscreen(true);
    
    gui.setup("Pacman");
//    gui.add(vehicleNum.set("Numnber of Pacman", 100 , 1 , 50) );
//    gui.add(ghostNum.set("Numnber of Ghost", 2 , 1 , 20) );
    gui.add(foodChance.set("Food Frequency", 0.5 , 0.01 , 1) );

    
    for (int i=0 ; i<50 ; i++){
        Vehicle v;
        vehicles.push_back(v);
        vehicles[i].setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    
    for (int i=0 ; i<2 ; i++){
        Ghost g;
        ghosts.push_back(g);
        ghosts[i].setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    
    for (int i=0 ; i<500 ; i++){
        Food f;
        foods.push_back(f);
        foods[i].setup(ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())));
    }


}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0 ; i<vehicles.size() ; i++){
        vehicles[i].eat(foods);
//        vehicles[i].seek(mouse);
            for (int j=0 ; j<ghosts.size() ; j++){
                vehicles[i].avoidGhost(ghosts[j].pos, 400 ,.04);
            }
        vehicles[i].boundaries();
        vehicles[i].update();
    }
    
    
    // vehicle to vehicle repulsion
    for (int i=0 ; i< vehicles.size(); i++){
        for (int j=0 ; j< i; j++){
            vehicles[i].addRepulsionForce(vehicles[j].pos, 50, ofRandom(0,5));
            vehicles[j].addRepulsionForce(vehicles[i].pos, 50, ofRandom(0,30));
        }
    }
    
    
    
    for (int i=0 ; i<ghosts.size() ; i++){
        ghosts[i].eat(vehicles);
        ghosts[i].boundaries();
        ghosts[i].update();
    }
    
    // ghost to ghost repulsion
    for (int i=0 ; i< ghosts.size(); i++){
        for (int j=0 ; j< i; j++){
            ghosts[i].addRepulsionForce(ghosts[j].pos, 30, 3);
            ghosts[j].addRepulsionForce(ghosts[i].pos, 30, 3);
        }
    }
    
    for (int i=0 ; i<foods.size() ; i++){
        foods[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0 ; i<vehicles.size() ; i++){
        vehicles[i].draw();
        
        if (vehicles[i].health<0){
            vehicles.erase(vehicles.begin()+i);
        }
    }
    
    for (int i=0 ; i<ghosts.size() ; i++){
        ghosts[i].draw();
    }
    
    for (int i=0 ; i<foods.size() ; i++){
        foods[i].draw();
    }
    
   
    // 5% of chance to add a piece of food
    if ( ofRandom(1) < foodChance ){ // 0.05
        for (int i=0 ; i< 1; i++){
            Food f;
            foods.push_back(f);
            foods[foods.size()-1].setup(ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())));
        }
    }
    
    gui.draw();
    
    
    
    string message = "Pacmans: " + ofToString(vehicles.size()) + "\n" + "Ghosts: " + ofToString(ghosts.size()) + "\n" + "Framerate: " + ofToString(ofGetFrameRate());
    ofSetColor(255);
    ofDrawBitmapString( message  , 10, 100);

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
    
    for (int i=0 ; i< 1; i++){
        Food f;
        foods.push_back(f);
        foods[foods.size()-1].setup(ofPoint(x,y));
    }

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
