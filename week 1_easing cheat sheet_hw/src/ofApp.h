#pragma once

#include "ofMain.h"

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

        ofPoint firstPos;
        ofPoint secPos;
        ofPoint thirdPos;
        ofPoint fourthPos;
        ofPoint fifPos;
        ofPoint sixthPos;
        ofPoint posA;
        ofPoint posB;
    
        float pct;
        float inQuint(float t);
        float outSine(float t);
        float inSine(float t);
        float outExpo(float t);
        float outBounce(float t);
    
        float r1;
        float r2;
        float r3;
        float r4;
        float r5;
        float r6;
};
