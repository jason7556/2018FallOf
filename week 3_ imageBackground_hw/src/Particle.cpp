//
//  Particle.cpp
//  week 3_ imageBackground_hw
//
//  Created by Jason Chen on 20/09/2018.
//

#include "Particle.hpp"


Particle::Particle(){
    
    pos.set(0,0,0);
    vel.set(0,0,0);
    acc.set(0,0,0);
    damp = 0.9;
    
}

//--------------------------------------------------------------
void Particle::setup(ofPoint pos_){
    
    pos = pos_;
    
    vel.set( ofRandom(-10,10) , ofRandom(-10,10));
    
}

//--------------------------------------------------------------
void Particle::update(ofColor _color){
    
    
    color = _color;
    
    
    vel += acc; // add acceleration to velocity
    vel *= damp;
    pos += vel; // add velocity to position
    
    acc *= 0;
    
    if (pos.x < 0 || pos.x > ofGetWidth() || pos.y <0 || pos.y > ofGetHeight() ){
        pos.set( ofPoint( ofRandom(ofGetWidth()) , ofRandom(ofGetHeight()) ));
    }
    
    
}

//--------------------------------------------------------------
void Particle::addForce(ofPoint force){
    acc += force;
}

//--------------------------------------------------------------
void Particle::addAttractionForce( ofPoint _pos, float _rad, float scale ){
    
    // 1. Calculate difference between my position and attractor position
    
    ofPoint diff = _pos - pos;
    
    
    
    // 2. Test if we are close enough to receive attraction force
    
    if(diff.length() < _rad){
        ofLog() << "Attract";
        // first scale from 1 to 0 bty dividing by the radius
        // then 1.0 - this value so that closer
        
        // (diff.length() / _rad) give us 0 to 1
        diff *= 1.0 - (diff.length() / _rad);
        
        // same as acc += diff*scale;
        addForce(diff*scale);
        }
    
}
//--------------------------------------------------------------
void Particle::addRepulsionForce( ofPoint _pos, float _rad, float scale  ){
        
        ofPoint diff = _pos-pos;
        
        if(diff.length() < _rad){
            ofLog() << "Repulse";
            
            diff *= 1.0 - (diff.length() / _rad);
            
            addForce(-diff*scale);
            
        }
        
}

//--------------------------------------------------------------
void Particle::draw(){
    
//    if(color.r > 150 && color.g > 150 && color.b > 150){
        ofSetColor(color);
//    } else {
//        ofSetColor(0);
//    }
    
    
    ofDrawCircle(pos.x, pos.y , 5, 5);

}
