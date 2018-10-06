//
//  Particle.cpp
//  week 1_easing animation_hw
//
//  Created by Jason Chen on 09/09/2018.
//

#include "Particle.hpp"


void Particle::reset() {
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    pos.x = ofRandom(-400,width+400);
    pos.y = ofRandom(-400,height+400);
    pos.z = ofRandom(-500,30);
    
    vel.x = ofRandom(-4.9,4.9);
    vel.y = ofRandom(-4.9,4.9);
    vel.z = ofRandom(-4.9,4.9);
    
    drag = ofRandom(0.95,0.998);
    
    force = ofPoint(0,0,0);
    
}

void Particle::update(ofPoint mouse) {
    
    ofPoint attractor = ofPoint(mouse.x,mouse.y);
        
    force = attractor - pos;
        
    force.normalize();
    
    vel *= drag;
    vel += force * 0.06;
    
    pos += vel;
    
    
    if (pos.x<width/2){
    r = ofMap(pos.x, 0, width/2, 0.2, 1.3);
    }
    
    else if (pos.x>width/2){
        r = ofMap(pos.x, width/2, width, 1.3, 0.2);
    }
    
    
    
    
    if(pos.x>ofGetWidth() || pos.x<0 || pos.y>height || pos.y<0 ){
        reset();
    }
    
//    if(pos.x>ofGetWidth()){
//        pos.x = 0;
//    }
//
//    if(pos.x<0){
//        pos.x = ofGetWidth();
//    }
//
//    if(pos.y>ofGetHeight()){
//        pos.y=0;
//    }
//
//    if(pos.y<0){
//        pos.y=ofGetHeight();
//    }

    
    
}


void Particle::draw() {
    
    ofSetColor(255);
    ofDrawCircle(pos, r);

}
