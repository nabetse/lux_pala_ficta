#pragma once

#include "ofxEasyFft.h"

class procesaFFT {
public:

	ofxEasyFft fft;
	vector <float> fftSpectrum;


	int     numBins; // numero de muestras
	int     numFFTbins; //cuandas columnas de analisis
	float   FFTpercentage; //que porcenta1je del FFT se pasa a analisis. Usualmente 20% de todo el espectro 0-5khz
	float   exponent; // factor para valorar los altos un poco mas que los bajos, ya que los bajos tinen  mas energia en FFT - en un rango de 1.0-1.6
	bool	normalize;
	float   maxSound;
	int     loudestBand;

	void setExponent(float _Exponent);

	void setup();
	void update();

private:
	float   avgMaxSoundOverTime;
	vector <float> graphMaxSound;
};
