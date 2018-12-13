#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxOpenCv.h"

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
    
//    ofVideoPlayer vidPlayer;
    
    ofVideoGrabber cam;
    
    ofxCvColorImage         colorImg;
    ofxCvGrayscaleImage     grayImage;
    ofxCvGrayscaleImage     grayBg;
    ofxCvGrayscaleImage     grayDiff;
    ofxCvGrayscaleImage     graySmoothed;
    
    ofxCvContourFinder     contourFinder;
    
    bool captureBackground;
    
    
    ofxBox2d  box2d;              //    the box2d world
    vector<shared_ptr<ofxBox2dCircle> > circles;          //    default box2d circles
    
    ofxBox2dEdge shape;
    
    ofPoint target;
    
    bool nHasVerts = false;
    
    vector<shared_ptr<ofxBox2dPolygon>> polyShapes;
    
    int counter;
    
    float r = 30;
		
};