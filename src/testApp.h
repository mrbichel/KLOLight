#pragma once

#include "ofMain.h"

#include "ofxOsc.h"
#include "ofxDmx.h"
#include "ofxArtnet.h"

#include "ofxGui.h"
#include "ofxOscParameterSync.h"

#define PORT 6666
#define OUTHEIGHT 1080
#define OUTWIDTH 1920

#define NUM_LAMPS 24

#define DYNAMIC_SIZE 16

#define NUM_SCENES 2


struct DynVar {
    ofParameter<float> param;
};

struct Lamp {
    int startChannel;
    
    ofColor color;
    bool on = true;
};

class testApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void updateLamps();
    
    
    ofxDmx dmx;
    
    bool  invert;
    
    bool  strobeOn;
    float strobeSpeed; // a fraction of clock
    float strobeIntensity;
    
    //int clock = 0;
    int oneSixtheenth = 0;
    
    DynVar dynList [DYNAMIC_SIZE];
    ofParameter<float> saturation;
    ofParameter<float> noise;
    ofParameter<int> clock;
    
    ofParameter<float> smoothness;
    
    ofParameter<ofColor> tint;
    ofParameter<ofColor> highlight;
    ofParameter<ofColor> backgroundColor;
    
    ofParameter<float> speed;
    
    ofParameter<int> currentScene;
    
    ofxArtnet artnet;
    
    ofFbo fbo;
    ofImage testImage;
    
    vector<Lamp> lamps;
    
    ofxOscParameterSync sync;
    
    ofParameterGroup parameters;

    ofxPanel gui;
    
    
};
