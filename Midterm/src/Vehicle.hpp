//
//  Vehicle.hpp
//  Midterm
//
//  Created by Jason Chen on 28/09/2018.
//

#pragma once

#include "ofMain.h"
#include "Food.hpp"
//#include "Ghost.hpp"

class Vehicle{
public:
    
    Vehicle();
    
    void setup(float x, float y);
    void applyForce(ofPoint force);
    void boundaries();
    void update();
    void addRepulsionForce(ofPoint _pos, float _rad, float scale);
    void avoidGhost(ofPoint _pos, float _rad, float scale);
    void seek(ofPoint target);
    void eat(vector<Food> &foods);
    void drawVelhicle();
    void draw();
    
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float maxSpeed;
    float maxForce;
    
    int mouthDeg;
    
    float angle;
    ofPoint lastPos;
    
    float health;
    
    float yyy;
    ofPoint boundary;
};
