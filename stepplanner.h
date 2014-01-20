#ifndef STEPPLANNER_H
#define STEPPLANNER_H
#include "body.h"

class StepPlanner
{
public:
    StepPlanner();
    friend ostream& operator<<(ostream& os, const StepPlanner p);
private:
    Body _b;
};

#endif // STEPPLANNER_H
