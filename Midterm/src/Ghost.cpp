//
//  Ghost.cpp
//  Midterm
//
//  Created by Jason Chen on 01/10/2018.
//

#include "Ghost.hpp"


Ghost::Ghost(){
    
};

//--------------------------------------------------------------
void Ghost::setup(float x, float y){
    
    pos.x = x;
    pos.y = y;
    
    vel.x = ofRandom(-5,5);
    vel.y = ofRandom(-5,5);
    
    maxSpeed = 10;
    maxForce = 0.1;
    
    boundary.set(ofGetWidth(),ofGetHeight());
    
}

//--------------------------------------------------------------
void Ghost::applyForce(ofPoint force){
    acc += force;
}

//--------------------------------------------------------------
void Ghost::boundaries(){
    
    ofPoint desired;
    float padding = 30;
    
    if(pos.x < padding){
        desired = ofPoint(maxSpeed,vel.y);
    } else if (pos.x > boundary.x - padding){
        desired = ofPoint(-maxSpeed,vel.y);
    }
    
    if (pos.y < padding){
        desired = ofPoint(vel.x,maxSpeed);
    } else if (pos.y > boundary.y - padding ){
        desired = ofPoint(vel.x,-maxSpeed);
    }
    
    if (desired != ofPoint(0,0)){
        desired.normalize();
        desired *= maxSpeed;
        ofPoint steer = desired - vel;
        steer.limit(maxForce);
        applyForce(steer);
    }
    
}

//--------------------------------------------------------------
void Ghost::update(){
    
    vel += acc;
    vel.limit(maxSpeed);
    pos += vel;
    
    acc *= 0;
    
    angle = atan2(lastPos.y - pos.y, lastPos.x - pos.x);
    lastPos = pos;
    
    
    counter += 0.2;
    
}

//--------------------------------------------------------------
void Ghost::addRepulsionForce( ofPoint _pos, float _rad, float scale  ){
    
    ofPoint diff = _pos-pos;
    
    if(diff.length() < _rad){
        
        diff *= 1.0 - (diff.length() / _rad);
        
        applyForce(-diff*scale);
        
    }
    
}

//--------------------------------------------------------------
void Ghost::seek(ofPoint target){
    
    ofPoint desired = target - pos;
    
    desired.normalize();
    desired *= maxSpeed;
    
    ofPoint steer = desired - vel;
    
    steer.limit(maxForce);
    
    applyForce(steer);
    
}

//--------------------------------------------------------------
void Ghost::eat(vector<Vehicle> &vehicles){
    
    float record = INFINITY;
    float closest = -1;
    
    for (int i=0 ; i<vehicles.size() ; i++){
        
        float d = ofDist(pos.x,pos.y, vehicles[i].pos.x, vehicles[i].pos.y);
        if (d < record){
            record = d;
            closest = i;
        }
    }
    
    // This is the moment of eating
    if (record < 20){
        vehicles.erase(vehicles.begin()+closest);
        
    } else if (closest > -1) {
        seek(vehicles[closest].pos);
    }
}


//--------------------------------------------------------------
void Ghost::drawGhost(){
    
//    ofBeginShape();
//
//    ofFill();
//    ofSetColor(255, 0, 0);
//    ofDrawCircle(0, 0, 15);
//
//    ofEndShape();
    
    float r = ofMap(ofNoise(counter), 0, 1, 150, 255);
    ofSetColor(r,0,0);
    ofFill();
    ofDrawCircle(0, 0, 50);
    ofDrawRectangle(-50, 00, 100, 50);
    

    ofDrawCircle(-37.5, 50, 12.5);
    ofDrawCircle(-12.5, 50, 12.5);
    ofDrawCircle(12.5, 50, 12.5);
    ofDrawCircle(37.5, 50, 12.5);
    
    ofSetColor(255);
    ofNoFill();
    ofFill();
    ofDrawEllipse(-15, 0, 10, 20);
    ofDrawEllipse(15,00,10,20);
}

//--------------------------------------------------------------
void Ghost::draw(){
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
//    ofRotate(ofRadToDeg(angle)-180);
    ofScale(0.6,0.6,0.6);
    drawGhost();
    
    ofPopMatrix();
    
}


