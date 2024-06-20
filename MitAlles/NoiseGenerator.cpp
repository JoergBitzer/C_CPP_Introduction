#include "NoiseGenerator.h"

UniformNoiseGenerator::UniformNoiseGenerator()
: m_gen(m_rd()),m_dis(0.0,1.0)
{
}

UniformNoiseGenerator::UniformNoiseGenerator(float minvalue, float maxvalue)
: m_gen(m_rd()),m_dis(minvalue, maxvalue)
{
}

void UniformNoiseGenerator::getNoise(std::vector<float> &dataOut)
{
    for (auto cc = 0 ; cc < dataOut.size(); ++cc)
    {
        dataOut[cc] = m_dis(m_gen);
    }
}
