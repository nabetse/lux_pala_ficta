#include "ofMain.h"
#include "ofApp.h"
#include "proyectorApp.h"
#include "ofAppGLFWWindow.h"
#include "GLFW/glfw3.h"

//========================================================================

int main() {
	int count;
	GLFWmonitor** monitors = glfwGetMonitors(&count);
	cout << "Total pantallas: " << count << endl;


	ofGLFWWindowSettings settings;

	if (count > 1) {
		// esto deberia ir afuera del if
		const GLFWvidmode * desktopMode = glfwGetVideoMode(monitors[0]);
		int anchoMon_1 = desktopMode->width;
		int altoMon_1 = desktopMode->height;

		int xM; int yM;
		glfwGetMonitorPos(monitors[1], &xM, &yM); //posoicion de la pantalla secundaria

		const GLFWvidmode * proyectorMode = glfwGetVideoMode(monitors[1]);
		int anchoProy_1 = proyectorMode->width;
		int altoProy_1 = proyectorMode->height;

		settings.setSize(anchoProy_1, altoProy_1);
		settings.setPosition(ofVec2f(xM, yM));
	}
	else {
		int anchoMon_1 = 1920; // COMO OBTENERLO???
		settings.setSize(1280, 720);
		settings.setPosition(ofVec2f(anchoMon_1-1280, 0));
	}
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	
	int anchoMon = 1920; // COMO OBTENERLO??? eliminarlo en ese caso
	settings.setSize(anchoMon - 1280, 720);
	settings.setPosition(ofVec2f(0, 0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<proyectorApp> projectApp(new proyectorApp);
	mainApp->proyector = projectApp;

	ofRunApp(mainWindow, projectApp);
	ofRunApp(guiWindow, mainApp);
	ofRunMainLoop();

}


