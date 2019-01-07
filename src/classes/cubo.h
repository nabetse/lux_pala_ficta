#pragma once


#include "ofMain.h"
#include "procesaFFT.h"

//class cubo : public ofBaseApp {
class cubo {
	public:

		bool bLog;
		int movimiento;
		int iniPos, iniTimeRot;
		float velRot, rotCube, constRot, impulso, velLine, finPos, arista;
		string escena;

		ofEasyCam cam;

		procesaFFT audioInput;
		
		void setup();
		void update();
		void draw();
};