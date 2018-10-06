//
//  Pacman.cpp
//  week 3_ forcesWithRotation_hw
//
//  Created by Jason Chen on 20/09/2018.
//

#include "Pacman.hpp"



Pacman::Pacman(){
    
    
};

// --------------------------------------------------------------
void Pacman::setup() {
    
    gifloader.load("pacman.gif");
    
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    vel.x = ofRandom(-8, 8);
    vel.y = ofRandom(-8, 8);
    
    friction = 0.999999999;
    
}


//--------------------------------------------------------------
void Pacman::addForce(ofPoint force){
    acc += force;
}

// --------------------------------------------------------------
void Pacman::update(){
    
    if (ofGetElapsedTimeMillis() % 5)
    {
        index++;
        if (index > gifloader.pages.size()-1) index = 0;
    }
    
    
    angle = atan2(lastPos.y - pos.y, lastPos.x - pos.x);
    lastPos = pos;
    
    
    vel += acc;
    vel *= friction;
    pos += vel;
    
    acc *= 0;
    
    
    
    if( pos.x > ofGetWidth()+30){
        pos.x = 0;
    }

    if ( pos.x < -30 ){
        pos.x = ofGetWidth();
    }

    if ( pos.y > ofGetHeight()+30 ){
        pos.y = 0;
    }

    if ( pos.y < -30){
        pos.y = ofGetHeight();
    }
    
//    if ( pos.x > ofGetWidth()+30 || pos.x < -30 || pos.y > ofGetHeight() +30 || pos.y < -30){
//        pos.x = ofRandom(ofGetWidth());
//        pos.y = ofRandom(ofGetHeight());
//        vel.x = ofRandom(-6, 6);
//        vel.y = ofRandom(-6, 6);
//    }
    
    

    
}



// --------------------------------------------------------------
void Pacman::follow( vector<Pacman> &pacmans){
    
    ofPoint aveVel;
    for (int i=0 ; i<pacmans.size() ; i++){
        //check each velocity, add them all together and find out the averaege
        //current vel += (averageVel-currentVel)/factor
        
        aveVel += pacmans[i].vel;
        
    }
    
    aveVel = aveVel / pacmans.size();
    
    ofPoint diff = aveVel - vel;
    
    vel += diff/50;
    
    
    
}

// --------------------------------------------------------------
void Pacman::attraction(vector<Pacman> &pacmans){
    
    for (int i=0 ; i<pacmans.size() ; i++){
        
        ofPoint delta = pos - pacmans[i].pos;
        delta.normalize();
        
        float dist = delta.length();
        
        if (dist < 20 ){
            
            float force = ofMap(dist, 0, 200, 1.3, 0);
            
            acc = -force * delta;
            
        }
        
    }
    
    
}

// --------------------------------------------------------------
void Pacman::separation(vector<Pacman> &pacmans){
    
    for (int i=0 ; i<pacmans.size() ; i++){
        
        ofPoint delta = pos - pacmans[i].pos;
        delta.normalize();
        
        float dist = delta.length();
        
        if (dist < 20 ){
            
            float force = ofMap(dist, 0, 100, 0.01, 0);
            
            acc = force * delta;
            
        }
        
    }
    
    
}

// --------------------------------------------------------------
void Pacman::addAttractionForce( ofPoint _pos, float _rad, float scale  ){
    
    
    // 1. Calculate difference between my position and attractor position
    
    ofPoint diff = _pos - pos;
    
    
    
    // 2. Test if we are close enough to receive attraction force
    
    if(diff.length() < _rad){
//        ofLog() << "Attract";
        // first scale from 1 to 0 bty dividing by the radius
        // then 1.0 - this value so that closer
        
        // (diff.length() / _rad) give us 0 to 1
        diff *= 1.0 - (diff.length() / _rad);
        
        // same as acc += diff*scale;
        addForce(diff*scale);
        
    }
    
    
    
}

// --------------------------------------------------------------
void Pacman::addRepulsionForce( ofPoint _pos, float _rad, float scale  ){
    
    ofPoint diff = _pos-pos;
    
    if(diff.length() < _rad){
//        ofLog() << "Repulse";
        
        diff *= 1.0 - (diff.length() / _rad);
        
        addForce(-diff*scale);
        
    }
    
    
    
}

// --------------------------------------------------------------
void Pacman::drawPacman(){
    
    img = gifloader.pages[index];
    pix = img.getPixels();
    img.draw(0, 0,10,10);
    
}


// --------------------------------------------------------------
void Pacman::draw(){
    
    ofPushMatrix();
    
    ofSetColor(255);
    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(angle)-180);
    ofScale(3,3,3);
    drawPacman();
    
    ofPopMatrix();

    
//    ofPushMatrix();
//    ofTranslate(pos.x, pos.y);
//    ofRotate(ofRadToDeg(angle)-90);
//    ofScale(0.1, 0.1);
//    ofSetColor(255);
//    img.draw(-img.getWidth()/2.0, -img.getHeight()/2.0);
//    ofPopMatrix();
    
    
    
}
