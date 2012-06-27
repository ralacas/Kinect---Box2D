#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"
#include "ofxKinect.h"
#include "ofxCvContourSimplify.h"

using namespace std;

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void drawBlobInsideMe(ofxCvGrayscaleImage &img, ofxCvBlob &blob);
    
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage depthImage;
    ofxCvGrayscaleImage debugImage;
    
    ofxKinect kinect;
    
    ofxCvContourFinder contourFinder;
    ofxCvContourSimplify analisis;

    vector<ofPoint>     simple;
    
    ofxBox2d fisica;
    ofxBox2dPolygon lineStrip;
    
    vector <ofxBox2dRect> rects;
    
    int numRect;
    
    int near;
    int far;
    
};