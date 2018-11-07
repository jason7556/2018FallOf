#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofSetFullscreen(true);
    
    ofSetCircleResolution(60);
    ofBackground(255);
    
    C = ofPoint(100,700);
    D = ofPoint(300,700);
    E = ofPoint(500,700);
    F = ofPoint(700,700);
    G = ofPoint(900,700);
    
    c.load("c.mp3");
    c.setMultiPlay(true);
    d.load("d.mp3");
    d.setMultiPlay(true);
    e.load("e.mp3");
    e.setMultiPlay(true);
    f.load("f.mp3");
    f.setMultiPlay(true);
    g.load("g.mp3");
    g.setMultiPlay(true);

    Ccolor = 255;
    Dcolor = 255;
    Ecolor = 255;
    Fcolor = 255;
    Gcolor = 255;
    
    Cvol = 0.1;
    Dvol = 0.1;
    Evol = 0.1;
    Fvol = 0.1;
    Gvol = 0.1;
    
    c.setVolume(Cvol);
    d.setVolume(Dvol);
    e.setVolume(Evol);
    f.setVolume(Fvol);
    g.setVolume(Gvol);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0 ; i< particles.size() ; i++){
        particles[i].update();
        
        float distC = ofDist(particles[i].pos.x, particles[i].pos.y, C.x, C.y);
        float distD = ofDist(particles[i].pos.x, particles[i].pos.y, D.x, D.y);
        float distE = ofDist(particles[i].pos.x, particles[i].pos.y, E.x, E.y);
        float distF = ofDist(particles[i].pos.x, particles[i].pos.y, F.x, F.y);
        float distG = ofDist(particles[i].pos.x, particles[i].pos.y, G.x, G.y);
        
        if (distC < 55){
//            particles[i].vel.y *= -0.8;
            c.play();
            Ccolor = 0;
        }
        Ccolor += 5;
//        Cvol = ofMap(distC, 10, 300, 0, 1);
        
        
        if (distD< 55){
//            particles[i].vel.y *= -0.8;
            d.play();
            Dcolor = 0;
        }
        Dcolor += 5;
        
        if (distE< 55){
//            particles[i].vel.y *= -0.8;
            e.play();
            Ecolor = 0;
        }
        Ecolor += 5;
        
        if (distF< 55){
//            particles[i].vel.y *= -0.8;
            f.play();
            Fcolor = 0;
        }
        Fcolor += 5;
        
        if (distG< 55){
//            particles[i].vel.y *= -0.8;
            g.play();
            Gcolor = 0;
        }
        Gcolor += 5;
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0 ; i< particles.size() ; i++){
        particles[i].draw();
    }
    
    
    ofSetColor(Ccolor);
    ofDrawCircle(C,50);
    ofSetColor(Dcolor);
    ofDrawCircle(D, 50);
    ofSetColor(Ecolor);
    ofDrawCircle(E, 50);
    ofSetColor(Fcolor);
    ofDrawCircle(F, 50);
    ofSetColor(Gcolor);
    ofDrawCircle(G, 50);
    
    
    ofSetColor(0);
    ofDrawBitmapString( "C"  , 100, 700);
    ofDrawBitmapString( "D"  , 300, 700);
    ofDrawBitmapString( "E"  , 500, 700);
    ofDrawBitmapString( "F"  , 700, 700);
    ofDrawBitmapString( "G"  , 900, 700);

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
    
    for (int i=0 ; i< 1 ; i++){
        Particle p;
        particles.push_back(p);
        particles[particles.size()-1].setup(ofPoint(x,y));
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


//    for (int i=0 ; i< 1 ; i++){
//        Particle p;
//        particles.push_back(p);
//        particles[particles.size()-1].setup(ofPoint(x,y));
//    }

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
