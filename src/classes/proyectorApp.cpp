#include "proyectorApp.h"
#include "GLFW/glfw3.h"

void proyectorApp::setup() {
	/*
	int cuantasPantallas;
	GLFWmonitor** monitors = glfwGetMonitors(&cuantasPantallas);
	cout << "Total pantallas conectadas " << cuantasPantallas << endl;
	if (cuantasPantallas > 1) {
		int xP, yP;
		glfwGetMonitorPos(monitors[0], &xP, &yP);
		const GLFWvidmode * guiMode = glfwGetVideoMode(monitors[0]);
		int anchoGUImon = guiMode->width;
		int altoGUImon = guiMode->width;
		//cout <<  
		glfwGetMonitorPos(monitors[1], &xP, &yP);
		const GLFWvidmode * proyectorMode = glfwGetVideoMode(monitors[1]);
		int anchoProyectormon = proyectorMode->width;
		int altoProyectormon = proyectorMode->width;
		//proyector->ofSetWindowPosition(0, 0);
		ofSetWindowPosition(0, 0);
	}
	else {
		int xP, yP;
		glfwGetMonitorPos(monitors[0], &xP, &yP);
		const GLFWvidmode * guiMode = glfwGetVideoMode(monitors[0]);
		int anchoGUImon = guiMode->width;
		int altoGUImon = guiMode->width;
		cout << "Ancho pantalla es " << anchoGUImon;

		//proyector->ofSetWindowPosition(0, 0);
		ofSetWindowPosition(anchoGUImon - 1280, 0);
		ofSetWindowShape(1280, 720);
	}


	ofSetWindowPosition(0, 0);
	ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
	*/
	ofBackground(0);
	ofSetVerticalSync(false);

	hipercubo.setup();
}

void proyectorApp::update() {
	hipercubo.update();
}

void proyectorApp::draw() {
	hipercubo.draw();
}

void proyectorApp::setWindowPosition(int x, int y) {
	ofSetWindowPosition(x, y);
}
