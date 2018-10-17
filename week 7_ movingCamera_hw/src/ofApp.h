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
        void cameraMoves();
        void cameraTurn();
    
    float inOutSine (float t);
    float inQuad (float t);
    
    
    
    ofEasyCam cam;
    vector<ofVec3f> boxes;
    ofVec3f boxPos;
    
    ofLight light;
    
    
    ofVec3f camPos;
    ofVec3f prePos;
    ofVec3f desPos;
    ofVec3f folloPos;
    ofVec3f pfolloPos;
    
    
    
    float pct;
    
    ofColor color;
    
    int lookAtMe;
    
    bool count;
    
    float x,y,z;
    
    float counter;
    
		
};
