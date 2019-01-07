#include "ofApp.h"
#include "GLFW/glfw3.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	//ofSetWindowPosition(0, 0);
	//ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
	
	/*
	consola = new GUIcontrol();
	consola->setup();
	*/
	gui.setup();
	backgroundColor = ofColor(114, 144, 154);

	nivelCarpeta = -1;
	folderStripper(ofToDataPath("", true));

	cualEscena = "";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetBackgroundColor(backgroundColor);
	//consola->dibujaConsola();


		gui.begin();

		if (ImGui::BeginMainMenuBar()) {

			if (ImGui::BeginMenu("Archivo"))
			{
				if (ImGui::MenuItem("Recargar", "Ctrl+L")) {
					nivelCarpeta = -1;
					folderStripper(ofToDataPath("", true));
				}
				ImGui::Separator();
				if (ImGui::MenuItem("Cerrar", "Alt+F4")) {}

				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}

		ImGui::SetNextWindowSize(ofVec2f(200, 500), ImGuiSetCond_FirstUseEver);
		ImGui::SetNextWindowPos(ImVec2(2, 20), ImGuiCond_FirstUseEver);
		ImGui::Begin(" - A P U N T A D O R -");
		//ImGui::Text("Hello");
		//ImGui::End();

		ImGuiWindowFlags window_flags = 0;
		if (false)  window_flags |= ImGuiWindowFlags_NoTitleBar;
		if (false) window_flags |= ImGuiWindowFlags_NoScrollbar;
		if (false)     window_flags |= ImGuiWindowFlags_MenuBar;
		if (false)      window_flags |= ImGuiWindowFlags_NoMove;
		if (false)    window_flags |= ImGuiWindowFlags_NoResize;
		if (true)  window_flags |= ImGuiWindowFlags_NoCollapse;
		if (false)       window_flags |= ImGuiWindowFlags_NoNav;

		if (ImGui::CollapsingHeader("ESCENAS", NULL, window_flags))
		{
			static int e = 0;

			for (int i = 0; i < vEscenas.size(); i++) {
				const char* n = vEscenas[i];
				if (ImGui::RadioButton(n, &e, i)) cualEscena = vEscenas[i];
				//if(i<vEscenas.size()-1) ImGui::SameLine();
			}
			/*
			ImGui::RadioButton("radio a", &e, 0); ImGui::SameLine();
			ImGui::RadioButton("radio b", &e, 1); ImGui::SameLine();
			ImGui::RadioButton("radio c", &e, 2);
			*/
		}

		if (ImGui::CollapsingHeader("MATERIALES", NULL, window_flags)) {
			ImGui::Text("archivos");
		}

		ImGui::End();

		correEscena();
		//ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiCond_FirstUseEver);
		//ImGui::SetNextWindowSize(ImVec2(400, 400), ImGuiCond_FirstUseEver);
		/*
		if (!ImGui::Begin("ESCENA"))
		{
		ImGui::End();
		return;
		}
		ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.65f);

		if (ImGui::CollapsingHeader("Escenas"))
		{
		static int e = 0;
		for (string n : vEscenas) {
		ImGui::RadioButton(n, 0, 0); ImGui::SameLine();
		}
		}
		ImGui::End();
		*/
		gui.end();

	}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofLogVerbose(__FUNCTION__) << key;
	switch (key)
	{

	case 's':
	{
		break;
	}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	ofLogVerbose(__FUNCTION__) << key;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//proyector->hipercubo.movimiento++;
	//proyector->setWindowPosition(ofRandom(400), ofRandom(400));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::correEscena()
{
	//cualEscena = 
	if (cualEscena == "") {}
	else {
		ImGui::SetNextWindowSize(ofVec2f(400, 500), ImGuiSetCond_FirstUseEver);
		ImGui::SetNextWindowPos(ImVec2(204, 20), ImGuiCond_FirstUseEver);
		const char* n = cualEscena.c_str();
		ImGui::Begin(n);

		if (cualEscena == "Cubo") {
			ImGui::Text("Animacion --------------------------");
			if (ImGui::ArrowButton("##left", ImGuiDir_Left)) proyector->hipercubo.movimiento--;
			ImGui::SameLine();
			if (ImGui::ArrowButton("##right", ImGuiDir_Right)) proyector->hipercubo.movimiento++; 
			ImGui::SameLine(0.0f, 10.0f);
			ImGui::Text("AVANZAR");
			ImGui::SameLine(0.0f, 70.0f);
			ImGui::Text("Movimiento # ");
			ImGui::SameLine(0.0f, 0.0f);
			ImGui::Text("%d", proyector->hipercubo.movimiento);
			ImGui::Separator();
			ImGui::Text("Analisis --------------------------------");
			// parametros espectro
			int cuantosBins = proyector->hipercubo.audioInput.fftSpectrum.size();
			string salidaTXT = "Espectro de " + ofToString(cuantosBins) + " bandas.";
			ImGui::Text(salidaTXT.c_str()); ImGui::SameLine();
			ImGui::Checkbox(" Normalizado", &proyector->hipercubo.audioInput.normalize);
			bool normalizado = proyector->hipercubo.audioInput.normalize;
			// ESPECTRO	
			float* arr = new float[cuantosBins];

			for (int i = 0; i < cuantosBins; i++) {
				arr[i] = proyector->hipercubo.audioInput.fftSpectrum[i];
			}
			cout << endl;
			if (normalizado) {
				ImGui::PlotHistogram("1.0", arr, cuantosBins, 0, NULL, 0.0f, 1.0f, ImVec2(0, 80));
			}
			else {
				ImGui::PlotHistogram("400", arr, cuantosBins, 0, NULL, 0.0f, 400.0f, ImVec2(0, 80));
			}
			
			// control animacion
			salidaTXT = "Banda pico > # "
				+ ofToString(proyector->hipercubo.audioInput.loudestBand)
				+ " valor:" + ofToString(proyector->hipercubo.audioInput.maxSound);
			ImGui::Text(salidaTXT.c_str());
			//ImGui::Text("Banda pico > "); ImGui::SameLine();
			//ImGui::Text("%d", proyector->hipercubo.audioInput.loudestBand);
			ImGui::Separator();
			ImGui::Text("Motor de voz -----------------------");
			ImGui::Text("Usando valor promedio entre barras");
			static int minBar = 8, maxBar = 8;
			ImGui::DragIntRange2("", &minBar, &maxBar, 1, 0, cuantosBins, "%d >", "< %d ");

			float promedio = 0;
			if (maxBar > minBar) {
				for (int i = minBar; i < maxBar; i++) {
					//promedio += arr[i];
					promedio += proyector->hipercubo.audioInput.fftSpectrum[i];
				}
				promedio = promedio / (maxBar - minBar);
			}
			else if (maxBar = minBar) promedio = proyector->hipercubo.audioInput.fftSpectrum[minBar];
			delete[] arr;
			
			static bool activado = false;
			if (ImGui::Checkbox("Activar", &activado)) proyector->hipercubo.movimiento++;
			char buf[32];
			sprintf(buf, "%f", promedio, 1);
			static float fN = 0.0, f400 = 0.0; // valores para guardar en XML
			float impulso = 0;
			float factor = 0.4f;
			if (normalizado) {
				ImGui::ProgressBar(promedio, ImVec2(0.f, 0.f), buf);
				ImGui::SliderFloat("", &fN, 0.0f, 1.0f, "valor limite = %.2f");
				if (promedio > fN && activado) {
					impulso = (promedio - fN) / (1.0 - fN);
					proyector->hipercubo.impulso += impulso * factor;
				}

			}
			else {
				ImGui::ProgressBar(promedio / 400.0, ImVec2(0.f, 0.f), buf);
				ImGui::SliderFloat("", &f400, 0.0f, 400.0f, "impulso desde = %.2f");
				if (promedio > f400 && activado) {
					impulso = (promedio - f400) / (400.0 - fN);
					proyector->hipercubo.impulso += impulso * factor;
				}
			}

			ImGui::Text("%f", impulso);
			ImGui::Text("%f", proyector->hipercubo.impulso);
			ImGui::Text("%f", proyector->hipercubo.velLine);

			
			//ImGui::Text(buf, promedio);
			//ImGui::Text("%f", promedio); // sin buf sale porcentaje en la barra
			//ofLogVerbose(__FUNCTION__) << promedio << " y " << buf;

			
			//
			//ImGui::DragIntRange2()
		}

		ImGui::End();
	}
}

void ofApp::folderStripper(string ruta) {
	ofDirectory carpeta(ruta);
	std::vector<ofFile> archivos = carpeta.getFiles();
	if (archivos.size() < 1) {
		for (int j = 0; j < nivelCarpeta + 1; j++) cout << "     ";
		cout << " #### vacia ####" << endl;
	}
	else {
		for (size_t i = 0; i < archivos.size(); i++) {
			string nombre = archivos[i].getFileName();
			if (archivos[i].isDirectory()) {
				nivelCarpeta++;
				for (int j = 0; j < nivelCarpeta; j++) cout << "     ";
				cout << "Carpeta " << nombre << ":" << endl;;
				folderStripper(archivos[i].getAbsolutePath());
			}
			else {
				for (int j = 0; j < nivelCarpeta + 1; j++) cout << "     ";
				cout << nombre << endl;
			}
			if (i == archivos.size() - 1) nivelCarpeta--;
		}
	}


}