#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <vector>
#include "SinusGenerator.h"
#include "WaveOut.h"
int main() 
{
    int fs = 44100;
    int nrChannels = 1;
    SinusGenerator sinGen;
    std::string filename = "sin1000.wav";
    WaveOut waveOut(filename, fs, nrChannels, WaveOut::AudioFormat::INT16);
    
    //int len = 10000;
    std::vector<float> data;
    //data.resize(len);
    
    int NrOfBlocks = 250;
    int BlockLen = 256;
    data.resize(BlockLen);
    waveOut.open();

    for (auto bb = 0; bb < NrOfBlocks; bb++)
    {
        sinGen.getSinus(data);
        waveOut.write(data);
    }
    waveOut.close();

    //std::string filename = "noisedata3.bin";
    //writeVector(data, filename);
    
    return 0;
}