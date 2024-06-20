#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>



class SinusGenerator
{
public:
    SinusGenerator(float f0_Hz = 1000.f, float fs_Hz = 44100.f, float amp_dbFS = 0.f, float phase_rad = 0.f);
    ~SinusGenerator(){};
    void getSinus(std::vector<float> &dataOut);
    void reset();
    // setters
    void setFrequency(float f0_Hz){m_f0 = f0_Hz; computePhaseInc();};
    void setSamplingFrequency(float fs_Hz){m_fs = fs_Hz; computePhaseInc();};
    void setAmplitude(float amp_dbFS){m_amp = pow(10.f, amp_dbFS/20.f); };
    void setPhase(float phase_rad){m_phase = phase_rad; computePhaseInc();};
  
protected:
    float m_f0, m_fs, m_amp, m_phase;
    float m_incPhase, m_curPhase;
    void computePhaseInc();
};