#pragma once

#include <vector>

class MonoFIR
{
public:
    MonoFIR();
    MonoFIR(const std::vector<float> &bCoeffs);
    ~MonoFIR(){};
    void setCoeffs(const std::vector<float> &bCoeffs);
    int processSamples (std::vector<float> &data);
    void reset();



protected:
    std::vector<float> m_b;
    std::vector<float> m_bStates;
    int m_bLen;
    int m_readPos;
    int m_writePos;


};