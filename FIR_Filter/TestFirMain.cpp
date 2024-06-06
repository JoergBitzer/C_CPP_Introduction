#include <iostream>
#include <vector>
#include "FIR.h"

int main()
{
    std::vector<float> bCoeffs = { 0.1f, 0.2f, 0.3f, -0.4f, 0.5f };
    MonoFIR fir(bCoeffs);
    std::vector<float> data;
    
    // simplest test first. delta impulse should give the original coefficients
    // delta impulse with 100 samples
    data.resize(20);
    for (auto i = 0; i < data.size(); ++i)
    {
        data[i] = 0.f;
    }
    data[0] = 1.f;
    
    fir.processSamples(data);
    for (auto val : data)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}