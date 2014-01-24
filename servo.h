#ifndef SERVO_H
#define SERVO_H

class Servo
{
public:
    Servo();
    int MoveToAngle(double angle, int duration);
    void SetMinMaxPWM(int pwm_min,int pwm_max);
    void SetNullPWM(int pwm_null){_pwm_null=pwm_null;}
    int SetCalibrationValue(double angle,int pwm);
    double GetMinAngle();
    double GetMaxAngle();
    double GetAngle() const{return _angle;}
private:
    int _pwm;
    int _pwm_max;
    int _pwm_min;
    int _pwm_null;
    double _angle;
    double _k;
};

#endif // SERVO_H
