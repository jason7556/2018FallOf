//
//  Pacman.hpp
//  week 3_ forcesWithRotation_hw
//
//  Created by Jason Chen on 20/09/2018.
//

#pragma once

#include <ofMain.h>
#include "ofxGif.h"


class Pacman{
public:
    
    Pacman();
    
    void setup();
    void update();
    void drawPacman();
    void draw();
    void addForce(ofPoint force);
    void follow(vector<Pacman> &pacmans);
    void attraction(vector<Pacman> &pacmans);
    void separation(vector<Pacman> &pacmans);
    
    
    void addAttractionForce( ofPoint _pos, float _rad, float scale  );
    void addRepulsionForce( ofPoint _pos, float _rad, float scale  );
    
    ofPoint pos;
    ofPoint lastPos;
    ofPoint vel;
    ofPoint acc;
    ofColor color;
    
    float friction;
    float angle;
    
    
    
    ofPixels pix;
    
    ofxGIF::fiGifLoader gifloader;
    ofImage img;
    
    int index = 0;
    
};
