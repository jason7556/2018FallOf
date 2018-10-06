//
//  Vehicle.cpp
//  Midterm
//
//  Created by Jason Chen on 28/09/2018.
//

#include "Vehicle.hpp"


Vehicle::Vehicle(){
    
};

//--------------------------------------------------------------
void Vehicle::setup(float x, float y){
    
    pos.x = x;
    pos.y = y;
    
    vel.x = ofRandom(-5,5);
    vel.y = ofRandom(-5,5);
    
    mouthDeg = 360;
    
    health = 100;
    
    maxSpeed = 7;
//    maxSpeed = ofRandom(5,10);
    maxForce = 0.6;
    boundary.set(ofGetWidth(),ofGetHeight());
}

//--------------------------------------------------------------
void Vehicle::applyForce(ofPoint force){
    acc += force;
}

//--------------------------------------------------------------
void Vehicle::boundaries(){
    
    ofPoint desired;
    float padding = 20;
    
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
void Vehicle::update(){
    
    vel += acc;
    vel.limit(maxSpeed);
    pos += vel;
    
    acc *= 0;
    
    angle = atan2(lastPos.y - pos.y, lastPos.x - pos.x);
    lastPos = pos;
    
    if (health > 150){
        health = 150;
    }
    

}

//--------------------------------------------------------------
void Vehicle::addRepulsionForce( ofPoint _pos, float _rad, float scale  ){
    
    ofPoint diff = _pos-pos;
    
    if(diff.length() < _rad){

        diff *= 1.0 - (diff.length() / _rad);
        
        applyForce(-diff*scale);
        
    }
    
}

//--------------------------------------------------------------
void Vehicle::avoidGhost(ofPoint _pos, float _rad, float scale){
    
    ofPoint diff = _pos - pos; // the diff between ghosts' pos and vehicles' pos
    
    if (diff.length() < _rad){
        diff *= 1.0 - (diff.length() / _rad);
        applyForce(-diff*scale);
        ofLog() << "avoid!!!!!!";
    }

    
}

//--------------------------------------------------------------
void Vehicle::seek(ofPoint target){
    
    ofPoint desired = target - pos;
    
    desired.normalize();
    desired *= maxSpeed;
    
    ofPoint steer = desired - vel;
    
    steer.limit(maxForce);
    
    applyForce(steer);

}

//--------------------------------------------------------------
void Vehicle::eat(vector<Food> &foods){
    
    float record = INFINITY;
    float closest = -1;

    for (int i=0 ; i<foods.size() ; i++){
    
        float d = ofDistSquared(pos.x,pos.y, foods[i].pos.x, foods[i].pos.y);
        //ofDistS
        if (d < record){
            record = d;
            closest = i;
        }
    }
    
    // This is the moment of eating
    if (record < 100){
        health += 35;
        foods.erase(foods.begin()+closest);
    } else if (closest > -1) {
        seek(foods[closest].pos);
        health -= 0.5 ;
    }
}


//--------------------------------------------------------------
void Vehicle::drawVelhicle(){
    
    int cx = 0; // center of x
    int cy = 0;  // center of y
    
    float r;
    r = 25;

    
    
     mouthDeg = ofMap(sin(ofGetElapsedTimef()*7), -1, 1, 320, 360);
    
    // draw the fill one
    
    // the color fade depending on their health condition
    int c = ofMap(health, 0, 150, 0, 255);
    ofSetColor(c,c,0);
    ofFill();
    ofBeginShape();
    ofVertex(cx, cy);
    for( int i=(360-mouthDeg) ; i<mouthDeg+1 ; i += 2 )
    {
        float x1 = cx + cos(ofDegToRad(i)) * r ;
        float y1 = cy + sin(ofDegToRad(i)) * r ;
        ofVertex(x1,y1);
    }
    ofVertex(cx, cy);
    ofEndShape();
    
    
    // draw the stroke one
    ofSetColor(255,255,0);
    ofNoFill();
    ofBeginShape();
    ofVertex(cx, cy);
    for( int i=(360-mouthDeg) ; i<mouthDeg+1 ; i += 2 )
    {
        float x1 = cx + cos(ofDegToRad(i)) * r ;
        float y1 = cy + sin(ofDegToRad(i)) * r ;
        ofVertex(x1,y1);
    }
    ofVertex(cx, cy);
    ofEndShape();

}

//--------------------------------------------------------------
void Vehicle::draw(){
    
    ofPushMatrix();

    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(angle)-180);
//    ofScale(3,3,3);
    drawVelhicle();
    
    ofPopMatrix();
    
}


