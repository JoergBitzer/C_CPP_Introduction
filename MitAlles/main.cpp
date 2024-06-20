// This program shows how to use the NoiseGenerator, SinusGenerator, WaveOut and FIR classes
// it tests the switching of the FIR coefficients in a FIR filter
// the filter is a 3-tap FIR filter with the following coefficients:
// 0.5, 0.5, 0.0 lowpass
// 1.0, -2*cos(2*pi*f0/fs), 1.0 // notch filter
// 0.5, -0.5, 0.0 highpass

// (c) 2024 j.bitzer@TGM, Jade Hochschule, MIT License 
// https://opensource.org/licenses/MIT
// Version 1.0 2024-06-20 JB initial version
// Version 1.1 2024-06-20 JB added comments




#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>


#include "version.h"
#include "NoiseGenerator.h"
#include "SinusGenerator.h"
#include "WaveOut.h"
#include "FIR.h"

int main()
{
   // std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
    float fs = 48000;
    float AmpNoise = 0.1;
    float AmpSin = 0.5;

    UniformNoiseGenerator noiseGen(-AmpNoise,AmpNoise);
    float f0 = 1000.f;
    SinusGenerator sinGen(f0, fs, AmpSin, 0.f);
    MonoFIR fir;
    std::vector<float> bCoeffs;
    bCoeffs.resize(3);

    std::vector<float> noiseData;
    std::vector<float> sinData;
    std::vector<float> intermediateData;
    
    float len_s = 3;
    intermediateData.resize(fs);
    noiseData.resize(len_s * fs);
    sinData.resize(len_s * fs);
    sinGen.getSinus(sinData);
    noiseGen.getNoise(noiseData);
    for (size_t i = 0; i < sinData.size(); ++i)
    {
        noiseData[i] += sinData[i];
    }
    // block one. copy noise data to intermeidate data
    for (size_t i = 0; i < fs; ++i)
    {
        intermediateData[i] = noiseData[i];
    }
    bCoeffs.at(0) = 0.5;
    bCoeffs.at(1) = 0.5;
    bCoeffs.at(2) = 0.0;

    fir.setCoeffs(bCoeffs);
    fir.processSamples(intermediateData);
    // cop yintermediate data back to noise data
    for (size_t i = 0; i < fs; ++i)
    {
        noiseData[i] = intermediateData[i];
    }
    // block two. copy noise data to intermeidate data
    for (size_t i = 0; i < fs; ++i)
    {
        intermediateData[i] = noiseData[i+fs];
    }
    bCoeffs.at(0) = 1;
    bCoeffs.at(1) = -2*cos(2.f*M_PI*f0/fs);
    bCoeffs.at(2) = 1;
    fir.setCoeffs(bCoeffs);
    fir.processSamples(intermediateData);
    // cop yintermediate data back to noise data
    for (size_t i = 0; i < fs; ++i)
    {
        noiseData[i+fs] = intermediateData[i];
    }
    // block three. copy noise data to intermeidate data
    for (size_t i = 0; i < fs; ++i)
    {
        intermediateData[i] = noiseData[i+2*fs];
    }
    bCoeffs.at(0) = 0.5;
    bCoeffs.at(1) = -0.5;
    bCoeffs.at(2) = 0.0;
    fir.setCoeffs(bCoeffs);
    fir.processSamples(intermediateData);
    // cop yintermediate data back to noise data
    for (size_t i = 0; i < fs; ++i)
    {
        noiseData[i+2*fs] = intermediateData[i];
    }

    WaveOut writer("noisySin.wav");
    writer.write_file(noiseData);

    return 0;
}