//
//  Particle.hpp
//  week 1_easing animation_hw
//
//  Created by Jason Chen on 09/09/2018.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include <ofMain.h>

class Particle{
public:
    
    void reset();
    void update(ofPoint mouse);
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint force;
    
    float drag;
    
    float r;
    
    float width;
    float height;

};


#endif /* Particle_hpp */
