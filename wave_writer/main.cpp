#include <vector>
#include <random>
#include "WaveOut.h"
#include <cmath>

int main()
{
    int data_len = 100000;
    std::vector <float> data;
    data.resize(data_len);

    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dis(-2, 2);

    for (int cc = 0 ; cc < data.size(); cc++)
    {   
        double r2 = dis(gen);
        data.at(cc) = r2;
    }
    WaveOut writer("noise.wav");
    
    normalizeAudio(data, 0.0);
    
    writer.write_file(data);

    std::vector <std::vector<float>> data2dim;
    data2dim.resize(2);
    data2dim.at(0).resize(data_len);
    data2dim.at(1).resize(data_len);

    // copy positive and negative data to 2D vector
    for (int cc = 0 ; cc < data_len; cc++)
    {
        data2dim.at(0).at(cc) = data.at(cc);
        data2dim.at(1).at(cc) = -data.at(cc);
    }
    // generate sinus
    int fs = 44100;
    float f = 440;
    for (int cc = 0 ; cc < data_len; cc++)
    {
        data2dim.at(0).at(cc) = sin(2*M_PI*f*cc/fs);
        data2dim.at(1).at(cc) = sin(2*M_PI*f*cc/fs);
        data.at(cc) = sin(2*M_PI*f*cc/fs);;
    }

    normalizeAudio(data2dim, 0.0);
    normalizeAudio(data, 0.0);


    WaveOut writer2("sin_float32.wav",fs,1, WaveOut::AudioFormat::FLOAT32);
    writer2.write_file(data);

    WaveOut writer2b("sin_float64.wav",fs,1, WaveOut::AudioFormat::FLOAT64);
    writer2b.write_file(data);

    WaveOut writer3("sin_int32.wav",fs,1, WaveOut::AudioFormat::INT32);
    writer3.write_file(data);

    WaveOut writer4("sin_int24.wav",fs,1, WaveOut::AudioFormat::INT24);
    writer4.write_file(data);

    WaveOut writer5("sin_int16.wav",fs,1, WaveOut::AudioFormat::INT16);
    writer5.write_file(data);

    WaveOut writer6("sin_int16_blocks.wav",fs,1, WaveOut::AudioFormat::INT16);
    writer6.open();
    writer6.write(data);
    writer6.write(data);
    writer6.write(data);
    writer6.close();
    



    return 0;
    
}