#include "cubo.h"

void cubo::setup()
{

	cam.enableOrtho();
	// MOVIMIENTO CUBO
	movimiento = 0;
	arista = ofGetHeight()*.5;
	velLine = 0;
	iniPos = 0;
	finPos = 0;
	rotCube = 0;
	constRot = 0;
	//ofEnableAntiAliasing();
	ofDisableAntiAliasing();
	bLog = false;

	audioInput.setup();
	impulso = 0;
	escena = "";
}

void cubo::update(){
	audioInput.update();
	// ##############################
	velLine = min(4.0f, impulso + velLine);
}

void cubo::draw()
{
	cam.begin();
	ofPushMatrix();
	ofRotateX(20);
	ofPushMatrix();
	ofRotateY(-30);
	/*
	ofSetColor(255);
	ofBoxPrimitive cubo;
	cubo.set(arista);
	cubo.setResolution(1);
	cubo.drawWireframe();
	*/
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofNoFill();
	//ofSetColor(255, 0, 0);
	ofSetColor(240, 240, 255);
	ofSetLineWidth(10);

	

	if (movimiento == 1) {
		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, finPos, 0, 0);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 2) {
		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5);
		ofDrawLine(0, 0, 0, arista, 0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, 0, finPos, 0);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 3) {
		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5);
		ofDrawLine(0, 0, 0, arista, 0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5);
		ofDrawLine(0, 0, 0, 0, arista, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, arista * .5, arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(-finPos, 0, 0, 0, 0, 0);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 4) {
		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5);
		ofDrawLine(0, 0, 0, arista, 0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5);
		ofDrawLine(0, 0, 0, 0, arista, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, arista * .5, arista * .5);
		ofDrawLine(-arista, 0, 0, 0, 0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, arista * .5, arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, 0, -finPos, 0);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 5) {
		ofDrawRectangle(0, 0, arista * .5, arista, arista); // cara 1

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, 0, 0, -finPos);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 6) {
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5);
		ofDrawLine(0, 0, 0, 0, 0, -arista);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, -arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, finPos, 0, 0, 0, 0);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 7) {
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5);
		ofDrawLine(0, 0, 0, 0, 0, -arista);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, -arista * .5);
		ofDrawLine(0, arista, 0, 0, 0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, arista * .5, -arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, 0, 0, finPos);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 8) {
		ofDrawRectangle(0, 0, arista * .5, arista, arista); // 2 caras
		ofPushMatrix();
		ofRotateY(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, -arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, -finPos, 0, 0);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 9) {
		ofDrawRectangle(0, 0, arista * .5, arista, arista); // 2 caras
		ofPushMatrix();
		ofRotateY(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, -arista * .5);
		ofDrawLine(0, 0, 0, -arista, 0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, -arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, 0, 0, finPos);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 10) {
		ofDrawRectangle(0, 0, arista * .5, arista, arista); // 2 caras
		ofPushMatrix();
		ofRotateY(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateX(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, -arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, 0, finPos, 0);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
		}
		ofPopMatrix();
	}
	else if (movimiento == 11) {
		ofDrawRectangle(0, 0, arista * .5, arista, arista); // 3 caras
		ofPushMatrix();
		ofRotateY(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateX(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, -arista * .5);
		ofDrawLine(0, 0, 0, 0, arista, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, arista * .5, -arista * .5);
		finPos = min(arista, (finPos + velLine));
		ofDrawLine(0, 0, 0, 0, 0, finPos);
		ofDrawLine(0, 0, 0, finPos, 0, 0);
		if (finPos == arista) {
			movimiento++;
			finPos = 0;
			iniTimeRot = ofGetElapsedTimef();
		}
		ofPopMatrix();
	}
	else if (movimiento == 12) {
		velRot = abs(sin(ofGetElapsedTimef() - iniTimeRot)) * constRot;
		constRot = min(0.4, constRot + .01);
		rotCube += velRot + constRot;
		ofRotateY(rotCube);
		ofDrawRectangle(0, 0, arista * .5, arista, arista); // 6 caras
		ofPushMatrix();
		ofRotateY(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateX(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateX(-90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateY(-90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateX(180);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
	}
	else if (movimiento == 13) {
		/* desactivada disminucion de velocidad
		constRot = max(0.0, constRot - 0.001);
		velRot = max(0.0, velRot - 0.001);
		*/
		velRot = abs(sin(ofGetElapsedTimef() - iniTimeRot)) * constRot;
		constRot = min(0.4, constRot + .01);
		rotCube += velRot + constRot;
		ofRotateY(rotCube);
		ofDrawRectangle(0, 0, arista * .5, arista, arista); // 6 caras
		ofPushMatrix();
		ofRotateY(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateX(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateX(-90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateY(-90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
		ofPushMatrix();
		ofRotateX(180);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();

		//if (velRot == 0.0 && constRot == 0.0) {
		movimiento++;
		finPos = arista;
		//}

	}
	else if (movimiento == 14) {
		velRot = abs(sin(ofGetElapsedTimef() - iniTimeRot)) * constRot;
		constRot = min(0.4, constRot + .01);
		rotCube += velRot + constRot;

		finPos = max(0.0f, (finPos - velLine));

		ofRotateY(rotCube);

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, arista, 0, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5); // derecha
		ofDrawLine(0, 0, 0, 0, arista, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(arista * .5, arista * .5, arista * .5); // arriba
		ofDrawLine(-finPos, 0, 0, 0, 0, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(-arista * .5, arista * .5, arista * .5); // izquierda
		ofDrawLine(0, -arista + finPos, 0, 0, -arista, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofRotateY(180); // cara opuesta

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, arista, 0, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5); // derecha
		ofDrawLine(0, 0, 0, 0, arista, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(arista * .5, arista * .5, arista * .5); // arriba
		ofDrawLine(-finPos, 0, 0, 0, 0, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(-arista * .5, arista * .5, arista * .5); // izquierda
		ofDrawLine(0, -arista + finPos, 0, 0, -arista, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, arista * .5, arista * .5); // arriba
		ofDrawLine(0, 0, 0, 0, 0, -finPos);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, arista * .5, arista * .5); // arriba
		ofDrawLine(0, 0, -arista, 0, 0, -arista + finPos);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, 0, 0, -arista);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, 0, 0, -arista);
		ofPopMatrix();


		ofPopMatrix();
		if (finPos == 0) {
			movimiento++;
			finPos = arista;
		}
	}
	else if (movimiento == 15) {
		velRot = abs(sin(ofGetElapsedTimef() - iniTimeRot)) * constRot;
		constRot = min(0.4, constRot + .01);
		rotCube += velRot + constRot;

		finPos = max(0.0f, (finPos - velLine));

		ofRotateY(rotCube);
		//ofPushMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, arista, 0, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5); // derecha
		ofDrawLine(0, 0, 0, 0, finPos, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofRotateY(180); // cara opuesta

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, arista, 0, 0);
		ofPopMatrix();
		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5); // derecha
		ofDrawLine(0, 0, 0, 0, finPos, 0);
		ofPopMatrix();

		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, 0, 0, -arista);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, 0, 0, -arista);
		ofPopMatrix();

		if (finPos == 0) {
			movimiento++;
			finPos = arista;
		}

	}
	else if (movimiento == 16) {
		velRot = abs(sin(ofGetElapsedTimef() - iniTimeRot)) * constRot;
		constRot = min(0.4, constRot + .01);
		rotCube += velRot + constRot;

		ofRotateY(rotCube);

		ofPushMatrix();
		ofRotateX(90);
		ofDrawRectangle(0, 0, arista * .5, arista, arista);
		ofPopMatrix();
	}
	else if (movimiento == 17) {
		velRot = abs(sin(ofGetElapsedTimef() - iniTimeRot)) * constRot;
		constRot = min(0.4, constRot + .01);
		rotCube += velRot + constRot;

		finPos = max(0.0f, (finPos - velLine));

		ofRotateY(rotCube);
		//ofPushMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, finPos, 0, 0);
		ofPopMatrix();

		ofPushMatrix();
		ofRotateY(180); // cara opuesta

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, finPos, 0, 0);
		ofPopMatrix();

		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, -arista, 0, 0, -arista + finPos);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-arista * .5, -arista * .5, arista * .5); // abajo
		ofDrawLine(0, 0, 0, 0, 0, -finPos);
		ofPopMatrix();

		if (finPos == 0) {
			movimiento++;
			finPos = arista;
		}
	}

	ofPopStyle();
	ofPopMatrix();
	ofPopMatrix();
	cam.end();

	if (bLog) {
		string salida = ofToString(movimiento);
		ofDrawBitmapString(salida, 50, 50);
	}

	// ##############################
	impulso = max(0.0f, impulso-0.2f);
	//impulso *= 0.1;
	//velLine = max(0.0f, velLine-1.5f);
	velLine *= 0.92;
}
