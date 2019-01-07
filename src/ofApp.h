#pragma once

#include "ofMain.h"
#include "proyectorApp.h"
//#include "GUIcontrol.h"
#include "ofxImGui.h"

class ofApp : public ofBaseApp{

	public:
		shared_ptr<proyectorApp>	proyector;
		ofxImGui::Gui				gui;
		ImVec4						backgroundColor;

		vector <const char*>		vEscenas = { "Intro", "Cubo", "Manglar", "Palafito", "Pata" };
		void						correEscena();
		string						cualEscena;

		void						folderStripper(string ruta);
		int							nivelCarpeta;

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
		
};
