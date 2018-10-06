//
//  Particle.hpp
//  week 3_ imageBackground_hw
//
//  Created by Jason Chen on 20/09/2018.
//

#pragma once

#include "ofMain.h"


class Particle{
public:
    
    Particle();
    
    void setup(ofPoint pos_);
    void update(ofColor _color);
    void draw();
        void addForce(ofPoint force);
    void addAttractionForce( ofPoint _pos, float _rad, float scale  );
    void addRepulsionForce(  ofPoint _pos, float _rad, float scale  );

    
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    ofColor color;
    
    float damp;
    
};
