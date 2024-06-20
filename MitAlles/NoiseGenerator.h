#pragma once

#include <random>
#include <vector>

class UniformNoiseGenerator
{
public:
    UniformNoiseGenerator();
    UniformNoiseGenerator(float minvalue, float maxvalue);
    ~UniformNoiseGenerator();
    void getNoise(std::vector<float> &dataOut);

protected:
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_real_distribution<> m_dis;

};