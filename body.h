#ifndef BODY_H
#define BODY_H

#include "leg.h"
#include "servo.h"
#include "motor.h"

class Body
{
public:
    Body();
    friend ostream& operator<<(ostream& os, const Body b);
    int GetClearance(){return _clearance;}
    void SetClearance(int clearance){_clearance=clearance;}
    Leg* GetLeg(int leg){return &_legs[leg];}
    void UpdateLegsOrigin();
private:
    Leg* _legs;
    int _clearance;
    Servo _yaw;
    Motor _cleaner;
    Servo _hvost;
    double _tilt;
};

#endif // BODY_H
