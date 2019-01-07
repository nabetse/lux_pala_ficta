#pragma once

#include "ofMain.h"
#include "cubo.h"

class proyectorApp : public ofBaseApp {
public:

	cubo	hipercubo;

	void setWindowPosition(int x, int y);

	void setup();
	void update();
	void draw();
};


