#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <vector>
#include "NoiseGenerator.h"
#include "WaveOut.h"
/*
void writeVector(const std::vector<float> &data, const std::string &filename)
{
    std::ofstream fileout(filename, std::ios::binary);
    if (fileout.is_open()) 
    {
        
        /*
        for (auto val : data)
        {
            fileout.write(reinterpret_cast<char*>(&val), sizeof(val));
            std::cout << val << std::endl;
        }
        // *//*
        fileout.write(reinterpret_cast<const char*>(&data[0]), sizeof(float)*data.size());
        fileout.close();
    }

}
//*/
int main() 
{
    UniformNoiseGenerator noiseGen(-0.5,0.5);
    std::string filename = "noisedataBlock.wav";
    int fs = 44100;
    int nrChannels = 1;
    WaveOut waveOut(filename, fs, nrChannels, WaveOut::AudioFormat::INT16);
    
    //int len = 10000;
    std::vector<float> data;
    //data.resize(len);
    
    int NrOfBlocks = 40;
    int BlockLen = 256;
    data.resize(BlockLen);
    waveOut.open();

    for (auto bb = 0; bb < NrOfBlocks; bb++)
    {
        noiseGen.getNoise(data);
        waveOut.write(data);
    }
    waveOut.close();

    //std::string filename = "noisedata3.bin";
    //writeVector(data, filename);
    
    return 0;
}