#pragma once

#include "ofMain.h"

class Scene {
    
public:
    
    int index;
    string name;
    
    ofFbo fbo;
    bool enabled = true;
    
    Scene() {
    }
    virtual ~Scene(){}
    
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    virtual void exit(){}
    
    virtual void disable(){}
    virtual void enable(){}

    void setupScene(int width, int height, int i) {
        index = i;
        name = "Scene" + ofToString(i);
        fbo.allocate(width, height);
        setup();
    }
    
    void updateScene() {
        if(enabled) {
            update();
        }
    }
    
    void drawScene() {
        if(enabled) {
            fbo.begin();
            ofClear(0, 0);

            draw();
            
            fbo.end();
        }
        
    }
    
};
