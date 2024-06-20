#define _USE_MATH_DEFINES
#include <cmath>

#include "SinusGenerator.h"

SinusGenerator::SinusGenerator(float f0_Hz, float fs_Hz, float amp_dbFS, float phase_rad)
: m_f0(f0_Hz), m_fs(fs_Hz), m_amp(pow(10.f, amp_dbFS/20.f)), m_phase(phase_rad), m_curPhase(phase_rad)
{
    computePhaseInc();
}

void SinusGenerator::getSinus(std::vector<float> &dataOut)
{
    for (size_t i = 0; i < dataOut.size(); ++i)
    {
        dataOut[i] = m_amp * sin(m_curPhase);
        m_curPhase += m_incPhase;
        if (m_curPhase > 2*M_PI)
            m_curPhase -= 2*M_PI;
    }
}

void SinusGenerator::reset()
{
    m_curPhase = m_phase;
}

void SinusGenerator::computePhaseInc()
{
    m_incPhase = 2*M_PI * m_f0 / m_fs;
}
