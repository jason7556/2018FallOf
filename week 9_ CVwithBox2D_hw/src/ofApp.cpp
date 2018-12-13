#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    vidPlayer.load("fingers.mov");
//    vidPlayer.play();
//    vidPlayer.setLoopState(OF_LOOP_NORMAL);
    
    ofBackground(0);
    
    int w = 640;
    int h = 480;
    
    ofSetWindowShape(1280, 960);
    
    
    cam.setDeviceID(0);
    cam.setDesiredFrameRate(60);
    cam.initGrabber(w,h);
    
    colorImg.allocate(w,h);
    grayImage.allocate(w,h);
    grayBg.allocate(w,h);
    grayDiff.allocate(w,h);
    
    captureBackground = false;
    
    // setup box 2D
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createBounds();
    //    box2d.createGround();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
    
    nHasVerts = false;
    
    target.x = ofRandom(ofGetWidth());
    target.y = ofRandom(ofGetHeight());
    
    counter = 0;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    bool bNewFrame = false;
//    vidPlayer.update();
    cam.update();
//    bNewFrame = vidPlayer.isFrameNew();
    bNewFrame = cam.isFrameNew();
    
    if(bNewFrame){
        // work with the new camrea/video information
        
        // copy the video image into the color image object
        colorImg.setFromPixels(cam.getPixels());
        colorImg.mirror(false, true);
        // convert and store in grapyscale image
        grayImage = colorImg;
        
        
        if (captureBackground){
            grayBg = grayImage;
            captureBackground = false;
        }
        
        // the absolute difference and thresholding
        grayDiff.absDiff(grayImage,grayBg);
        grayDiff.threshold(80);
        
        graySmoothed = grayDiff;
        graySmoothed.blur(10);
        graySmoothed.threshold(80);
        for(int i=0; i<2; i++)  graySmoothed.erode();
        for(int i=0; i<3; i++)  graySmoothed.dilate();

        
        // pass the thresholded image to the contour finder
//        contourFinder.findContours(grayDiff, 20, (320*240)/3, 10, true,true);
        contourFinder.findContours(graySmoothed, 20, (320*240)/3, 10, true,true);

        
        // update the edge shape with the vertices of the largest contour
        if (contourFinder.nBlobs > 0){
            // if we already have previous vertices, clear them
            if(nHasVerts){
                shape.clear();
            }
            
            // add all the vertices of the contour
//            float scale = ofGetWidth() / 320;
             float scale = 2;
            for (int i = 0 ; i < contourFinder.blobs[0].pts.size() ; i++){
                shape.addVertex(contourFinder.blobs[0].pts[i].x*scale , contourFinder.blobs[0].pts[i].y*scale);
            }
            
            shape.create(box2d.getWorld());
            
            nHasVerts = true;
        }
        
    }
    
    
    for(int i=0; i<circles.size(); i++) {
        float centerX = circles[i].get()->getPosition().x;
        float centerY = circles[i].get()->getPosition().y;
        
        float dist = ofDist(centerX, centerY, target.x, target.y);
        
        if (dist < 30){
            counter += 1;
            target.x = ofRandom(ofGetWidth());
            target.y = ofRandom(100,ofGetHeight());
            r -= 1;
            
            circles.erase(circles.begin()+i);
        }
        
        
    }
    
    
    
    
    
    // update box 2D
    box2d.update();


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
//    ofSetColor(255);
//    cam.draw(0,0);
//    grayDiff.draw(0,0);
//    contourFinder.draw(0,0);
    
    ofSetColor(255);
    shape.draw();
    
    // draw the center point on the largest blob
    //    if (contourFinder.nBlobs > 0){
    //        int x = contourFinder.blobs[0].boundingRect.getCenter().x;
    //        int y = contourFinder.blobs[0].boundingRect.getCenter().y;
    //        ofSetColor(255, 0, 0);
    //        ofDrawCircle(x,y, 4);
    //
    //        ofSetColor(0, 0, 255);
    //        ofPoint center = contourFinder.blobs[0].centroid;
    //        ofDrawCircle(center, 4);
    //    }
    
    
    
    
    // draw box 2D
    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetHexColor(0xf6c738);
        circles[i].get()->draw();
    }
    
    
    ofSetColor(245, 20, 65);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(target.x,target.y, 50, 50);
    
    ofDrawBitmapStringHighlight("Points:"+ofToString(counter), 20, 50);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'b'){
        captureBackground = true;
    }
    
    else if(key == ' ') {
        
        circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(3.0, 0.53, 0.1);
        circles.back().get()->setup(box2d.getWorld(), ofRandom(200,ofGetWidth()-200), 0, r);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
