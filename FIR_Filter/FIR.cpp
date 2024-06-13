#include "FIR.h"

MonoFIR::MonoFIR()
{
    m_b.resize(1);
    m_b.at(0) = 1.f;
    m_bStates.resize(1);
    reset();
}

MonoFIR::MonoFIR(const std::vector<float> &bCoeffs)
{
    setCoeffs(bCoeffs);
}

void MonoFIR::setCoeffs(const std::vector<float> &bCoeffs)
{
    m_b = bCoeffs;
    m_bStates.resize(m_b.size());
    reset();
}

int MonoFIR::processSamples(std::vector<float> &data)
{
    // simple but slow method
    int bLen = m_b.size();
    int dLen = data.size();
    for (auto i = 0; i < dLen; ++i)
    {
        m_bStates.at(0) = data.at(i);
        float result = 0.f;
        for (auto j = 0; j < bLen; ++j)
        {
            result += m_b.at(j) * m_bStates.at(j);
        }
        data.at(i) = result;
        for (auto j = bLen - 1; j > 0; --j)
        {
            m_bStates.at(j) = m_bStates.at(j - 1);
        }
    }
    // refactor here


    return 0;
}

void MonoFIR::reset()
{
    int bLen = m_bStates.size();
    for (auto i = 0; i < bLen; ++i)
    {
        m_bStates.at(i) = 0.f;
    }
}
