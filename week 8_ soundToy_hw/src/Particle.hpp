//
//  Particle.hpp
//  week 8_ soundToy_hw
//
//  Created by Jason Chen on 2018/10/25.
//

#pragma once

#include "ofMain.h"


class Particle{
public:
    
    Particle();
    
    void setup(ofPoint _pos);
    void addForce(ofPoint force);
    void update();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    ofPoint gravity;
    
    
    
    
};
