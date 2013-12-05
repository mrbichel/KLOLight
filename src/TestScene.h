//
//  TestScene.h
//  kloLightBox
//
//  Created by Johan Bichel Lindegaard on 14/11/2013.
//
//


#pragma once

#include "ofMain.h"
#include "Scene.h"

class TestScene : public Scene {
    
public:
    
    void setup();
    void draw();
    void debugDraw();
    void update();
        
    float numtrails = 3;
    float length;
    int long lastadded;
    
    float circleRadius;
    
    bool random;
    bool clear;
    
    
    
};
