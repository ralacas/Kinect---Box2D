#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    kinect.init();
    kinect.open();
    
    //Setear los limites
    near = 115;
    far = 250;
    
    grayImage.allocate(kinect.width,kinect.height);
    depthImage.allocate(kinect.width,kinect.height);
    
    //Iniciar Box2D
    fisica.init();
    fisica.createBounds();
    fisica.setGravity(0, 10);
    fisica.checkBounds(true);
    
    //Numero de rectangulos
    numRect = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(100, 100, 100);
    kinect.update();
    
    grayImage.setFromPixels(kinect.getDepthPixels(),kinect.width,kinect.height);
    grayImage.mirror(false,true);    
    contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height), 20, true);
    
    if(contourFinder.nBlobs > 0){
        analisis.simplify(contourFinder.blobs[0].pts, simple, 1.0);
        ofPoint p;
        lineStrip.setup(fisica.getWorld());
        lineStrip.clear();
        for(int i=0; i<simple.size(); i++) {
            p.x = simple[i].x;
            p.y = simple[i].y;
            lineStrip.lineTo(p.x,p.y,0);
        }
    }
    
    //Crear los rectangulos
    while(numRect <=100){
        ofxBox2dRect rectangle;
		rectangle.setPhysics(ofRandom(2.0, 10.0), ofRandom(0.5, 1.0), 0.08);
        rectangle.setup(fisica.getWorld(), ofGetWidth()/2.0, 20, 10, 10);
        rects.push_back(rectangle);
        numRect++;
    }
    
    
    
    //Actualizar la fisica
    fisica.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255);
    //kinect.draw(420,10,400,300);
    //kinect.drawDepth(10, 10, 400, 300);
    
    //Dibujar los rectangulos
    for(int i=0;i<rects.size();i++){
        ofPushMatrix();
        ofTranslate(rects[i].getPosition().x, rects[i].getPosition().y, 0);
		ofRotate(rects[i].getRotation());
		ofSetColor(255, 255, 255);
        ofBeginShape();
        ofVertex(-rects[i].getWidth(), -rects[i].getHeight());
        ofVertex(rects[i].getWidth(), -rects[i].getHeight());
        ofVertex(rects[i].getWidth(), rects[i].getHeight());
        ofVertex(-rects[i].getWidth(), rects[i].getHeight());
        ofEndShape(true);
        ofPopMatrix();
    }
    lineStrip.draw();
}
//--------------------------------------------------------------
void testApp::exit(){
    kinect.close();
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}
