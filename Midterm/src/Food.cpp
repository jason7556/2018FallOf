//
//  Food.cpp
//  Midterm
//
//  Created by Jason Chen on 30/09/2018.
//

#include "Food.hpp"


Food::Food(){
    
        pos.x = 0;
        pos.y = 0;
    
};

// --------------------------------------------------------------
void Food::setup(ofPoint _pos){
    
    pos.x = _pos.x;
    pos.y = _pos.y;
    
}

// --------------------------------------------------------------
void Food::update() {

    r.r = 255;
    r.g = 255;
    r.b = 255;
    
    g.r = 0;
    g.g = 255;
    g.b = 0;
    
    color = r;

}

// --------------------------------------------------------------
void Food::draw() {
    
    ofFill();
    ofSetColor(color);
    ofDrawCircle(pos,5);
    
}
