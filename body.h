#ifndef BODY_H
#define BODY_H

#include "leg.h"

class Body
{
public:
    Body();
    friend ostream& operator<<(ostream& os, const Body b);
private:
    Leg* _legs;
};

#endif // BODY_H
