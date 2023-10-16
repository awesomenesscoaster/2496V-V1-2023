#include "main.h"

class PID{
public:
    float error = 0;
    float m_kp;
    float m_ki;
    float m_kd;
    float prev_error = 0;
    float integral = 0;
    float derivative = 0;
    float power = 0;
    float prev_power = 0;

    PID(float ki, float kp, float kd){
        m_kp = kp;
        m_ki = ki;
        m_kd = kd;
    }

    float calc(float target, float input, float integral_KI, float maxI, float slew){
        prev_power = power;
        prev_error = error;
        error = target - input;
        
        derivative = error-prev_error;

        if(std::abs(error) < integral_KI){
            integral = integral + error;
        }
        else{
            integral = 0;
        }

        if(integral > 0){
            integral = std::min(integral, maxI);
        }
        else{
            integral = std::max(integral, maxI);
        }

        power = m_kp*error + m_ki*integral + m_kd*derivative;
    }
};