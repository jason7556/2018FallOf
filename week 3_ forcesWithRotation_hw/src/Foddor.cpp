//
//  Foddor.cpp
//  week 3_ forcesWithRotation_hw
//
//  Created by Jason Chen on 21/09/2018.
//

#include "Foddor.hpp"


Foddor::Foddor(){
    
    
//    pos.x = -20;
//    pos.y = -20;
    
};


// --------------------------------------------------------------
void Foddor::setup(ofPoint _pos) {
    
    pos.x = _pos.x;
    pos.y = _pos.y;
    
    
}


// --------------------------------------------------------------
void Foddor::update() {
    
    
    
    
}

// --------------------------------------------------------------
void Foddor::draw() {
    
    ofSetColor(255, 255, 0);
    ofDrawCircle(pos,3);

}
