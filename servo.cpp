#include "servo.h"
#define ERROR_PWM_NULL_IS_NOT_SET -1
#define ERROR_PWM_OUT_OF_RANGE -2
#define ERROR_PWM_MIN_IS_NOT_SET -3
#define ERROR_PWM_MAX_IS_NOT_SET -4
#define OK 0

#define PWM_UNDEFINED 0

Servo::Servo()
    :_pwm(PWM_UNDEFINED)
    ,_pwm_max(PWM_UNDEFINED)
    ,_pwm_min(PWM_UNDEFINED)
    ,_pwm_null(PWM_UNDEFINED)
{
}

int Servo::MoveToAngle(double angle, int duration)
{
    int tmp;
    tmp=(int)(angle*(double)_k+0.5);
    if(tmp<_pwm_min || tmp>_pwm_max)
        return ERROR_PWM_OUT_OF_RANGE;
    _pwm=tmp;
    _angle=angle;
    return OK;
}

int Servo::SetCalibrationValue(double angle, int pwm)
{
    if(_pwm_null==PWM_UNDEFINED)
        return ERROR_PWM_NULL_IS_NOT_SET;
    _k=((double)(pwm-_pwm_null))/angle;
    return OK;
}

double Servo::GetMinAngle()
{
    if(_pwm_min==PWM_UNDEFINED)
        return ERROR_PWM_MIN_IS_NOT_SET;
    return (double)_pwm_min*_k;
}

double Servo::GetMaxAngle()
{
    if(_pwm_max==PWM_UNDEFINED)
        return ERROR_PWM_MAX_IS_NOT_SET;
    return (double)_pwm_max*_k;
}

void Servo::SetMinMaxPWM(int pwm_min, int pwm_max)
{
    _pwm_max=pwm_max;
    _pwm_min=pwm_min;
}
