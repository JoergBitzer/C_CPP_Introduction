#include <iostream>
#include <vector>
#include "FIR.h"

#include <chrono>
#include <cmath>

int main()
{
    int NrOfCoeffs = 25;
    std::vector<float> bCoeffs;
    bCoeffs.resize(NrOfCoeffs);
    for (auto i = 0; i < bCoeffs.size(); ++i)
    {
        bCoeffs[i] = 0.1f+i*0.1f*pow(-1,i);
    }


    MonoFIR fir(bCoeffs);
    std::vector<float> data;
    
    // simplest test first. delta impulse should give the original coefficients
    // delta impulse with 100 samples
    int test_len = 100000;
    data.resize(test_len);
    for (auto i = 0; i < data.size(); ++i)
    {
        data[i] = 0.f;
    }
    data[0] = 1.f;
    
    // measure execution time
    auto start = std::chrono::steady_clock::now();
    fir.processSamples(data);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time in nanoseconds : " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " mus" << std::endl;


/*    for (auto val : data)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
//*/    
    return 0;
}