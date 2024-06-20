#include <iostream>


#include "version.h"
#include "NoiseGenerator.h"
#include "WaveOut.h"

int main()
{
    std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;

    UniformNoiseGenerator noiseGen;
    std::vector<float> noiseData;
    float fs = 48000;
    float len_s = 3
    noiseData.resize(len_s * fs);
    noiseGen.getNoise(noiseData);

    WaveOut writer("noiseonly.wav");
    writer.write_file(noiseData);

    return 0;
}