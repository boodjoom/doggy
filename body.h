#ifndef BODY_H
#define BODY_H

#include "leg.h"

class Body
{
public:
    Body();
    friend ostream& operator<<(ostream& os, const Body b);
    int GetClearance(){return _clearance;}
    void SetClearance(int clearance){_clearance=clearance;}
    Leg* GetLeg(int leg){return &_legs[leg];}
private:
    Leg* _legs;
    int _clearance;
};

#endif // BODY_H
