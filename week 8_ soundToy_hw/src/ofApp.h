#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofPoint mouse;
    
    ofPoint C;
    ofPoint D;
    ofPoint E;
    ofPoint F;
    ofPoint G;
    
    ofColor Ccolor;
    ofColor Dcolor;
    ofColor Ecolor;
    ofColor Fcolor;
    ofColor Gcolor;
    
    float Cvol;
    float Dvol;
    float Evol;
    float Fvol;
    float Gvol;
    
    
    ofSoundPlayer c;
    ofSoundPlayer d;
    ofSoundPlayer e;
    ofSoundPlayer f;
    ofSoundPlayer g;
    
    
    vector<Particle> particles;
		
};
