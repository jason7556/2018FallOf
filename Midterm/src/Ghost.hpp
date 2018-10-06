//
//  Ghost.hpp
//  Midterm
//
//  Created by Jason Chen on 01/10/2018.
//

#pragma once


#include "ofMain.h"
#include "Vehicle.hpp"


class Ghost{
public:
    
    Ghost();
    
    void setup(float x, float y);
    void applyForce(ofPoint force);
    void boundaries();
    void update();
    void addRepulsionForce(ofPoint _pos, float _rad, float scale);
    void seek(ofPoint target);
    void eat(vector<Vehicle> &vehicles);
    void drawGhost();
    void draw();
    
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float maxSpeed;
    float maxForce;
    
    float angle;
    ofPoint lastPos;
    
    float counter;
    
    ofPoint boundary;
    
    
};
