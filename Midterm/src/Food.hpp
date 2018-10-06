//
//  Food.hpp
//  Midterm
//
//  Created by Jason Chen on 30/09/2018.
//

#pragma once

#include "ofMain.h"

class Food{
public:
    
    Food();
    
    void setup(ofPoint _pos);
    void update();
    void draw();
    
    ofPoint pos;
    
    ofColor g;
    ofColor r;
    ofColor color;

};
