#include "procesaFFT.h"

void procesaFFT::setup()
{
	numBins = 16384;
	fft.setup(numBins);
	fft.setUseNormalization(false);
	normalize = true;

	numFFTbins = 32;
	FFTpercentage = 0.14;
	exponent = 1.0;
}

void procesaFFT::setExponent(float _exponent) {
	this->exponent = _exponent;
}

void procesaFFT::update()
{
	fft.update();

	fftSpectrum.clear();
	float loudBand = 0;
	maxSound = 0;

	for (int i = 0; i<numFFTbins; i++) {
		fftSpectrum.push_back(0); 
	}

	// valor promedio para el numero de columnas escogido
	vector<float>&buffer = fft.getBins();

	for (int i = 0; i<fftSpectrum.size(); i++) { 
		float bin_size = buffer.size()*FFTpercentage;

		for (int j = (bin_size*((float)i / numFFTbins)); j<bin_size*((float)1 / numFFTbins) + (bin_size*((float)i / numFFTbins)); j++) { 
			fftSpectrum[i] = fftSpectrum[i] + buffer[j] * 10000; 
		}

		fftSpectrum[i] = abs((fftSpectrum[i] / (bin_size*(float)1 / numFFTbins))*(1 + pow(i, exponent) / numFFTbins));

        // banda con el valor maximo
		if (maxSound<fftSpectrum[i]) {
			maxSound = fftSpectrum[i];
			loudestBand = i;
		}
	}

	graphMaxSound.push_back(maxSound); //acumular sonidos mas altos

	float accumMaxSounds = 0;
	for (int i = 0; i<graphMaxSound.size(); i++) {
		accumMaxSounds = accumMaxSounds + graphMaxSound[i];
	}

	avgMaxSoundOverTime = accumMaxSounds / graphMaxSound.size(); //promedio en cierta cantidad de frames

	float meanSum = 0;
	float mean, stdDev, stdDevAccum, variance, deviation;

	float spectralCentroidAccum, spectralWeightsAccum, spectralWeights;

	for (int i = 0; i<fftSpectrum.size(); i++) {

		if (normalize) {
			fftSpectrum[i] = ofMap(fftSpectrum[i], 0, avgMaxSoundOverTime, 0, 1, true);
		}


		
	}
}
