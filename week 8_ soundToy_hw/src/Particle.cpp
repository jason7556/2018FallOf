//
//  Particle.cpp
//  week 8_ soundToy_hw
//
//  Created by Jason Chen on 2018/10/25.
//

#include "Particle.hpp"

Particle::Particle(){
    
    pos.x = 0;
    pos.y = 0;
    
};


//--------------------------------------------------------------
void Particle::setup(ofPoint _pos){
    
    pos.x = _pos.x;
    pos.y = _pos.y;
    
    vel.x = ofRandom(-2,2);
    
    gravity.y = 0.98;
    
}

//--------------------------------------------------------------
void Particle::addForce(ofPoint force){
    acc += force;
}



//--------------------------------------------------------------
void Particle::update(){
    
    acc += gravity;
    vel += acc;
    pos += vel;
    
    acc *= 0;
}

//--------------------------------------------------------------
void Particle::draw(){
    
    ofDrawCircle(pos, 5);
    
}
