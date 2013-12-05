#include "testApp.h"


void testApp::setup() {
    
    ofSetLogLevel(OF_LOG_ERROR);
    
    ofSetWindowTitle("KLO Light Control");
    
    ofSetFrameRate(60);
    
    // dmx.connect("tty.usbserial-ENS8KBA6", 24);
    // for i in lamps
    // setup
    // artnet.setup("169.254.78.32");
    
    // fbo.allocate(512, 1);
    
    
    parameters.setName("klolys");
    
    
    for(int i=0; i<DYNAMIC_SIZE; i++) {
        
        parameters.add(dynList[i].param.set("dyn"+ofToString(i),0.5,0.0,1.0));
    }
    
    parameters.add(saturation.set("Saturation",0.0,0.0,1.0));
    parameters.add(noise.set("Noise",0.0,0.0,1.0));
    parameters.add(clock.set("Clock", 0));
    
    parameters.add(currentScene.set("Scene", 0, 0, NUM_SCENES));
    
    parameters.add(tint.set("Tint", ofColor(0,0,255,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    parameters.add(highlight.set("Highlight", ofColor(0,200,200,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    parameters.add(backgroundColor.set("Background",
                            ofColor(0,200,200,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    
    
    
	gui.setup(parameters);
    
    
	// by now needs to pass the gui parameter groups since the panel internally creates it's own group
	sync.setup((ofParameterGroup&)gui.getParameter(),6666,"localhost",6667);
    
    
    for(int i=0; i < NUM_LAMPS; i++) {
        Lamp l;
        l.startChannel = (i*3)+1;
        l.color = ofColor(255,255,255);
        lamps.push_back(l);
    }
    
    
}

//--------------------------------------------------------------
void testApp::update() {
    
    sync.update();
    
    updateLamps();
    
    
}


void testApp::updateLamps() {
    // for i in lamps update
    // take into account, strobe, saturation, noise, dynamic ranges

    
    
    for(int i=0; i < NUM_LAMPS; i++) {
        
        int d = ofMap(i, 0, NUM_LAMPS, 0, DYNAMIC_SIZE);
        
        
        lamps[i].color = highlight.get()*dynList[d].param.get();
        
        //for(int d)
        
        
       // dmx.setLevel(lamps[i].startChannel, lamps[i].color.r);
       // dmx.setLevel(lamps[i].startChannel+1, lamps[i].color.g);
       // dmx.setLevel(lamps[i].startChannel+2, lamps[i].color.b);
    }
    
}

//--------------------------------------------------------------
void testApp::draw() {
    
 
    // draw osc receiving status
    

    // draw lamp debug
    for(int i=0; i < NUM_LAMPS; i++) {
        
        ofPushMatrix();
        ofTranslate((i*70) + 10, 10);
        ofSetColor(lamps[i].color);
        ofRect(0,0,60,60);
        ofPopMatrix();
        
    }
    
    gui.draw();
    
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

//--------------------------------------------------------------
void testApp::exit()
{

}

