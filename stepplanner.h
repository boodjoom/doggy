#ifndef STEPPLANNER_H
#define STEPPLANNER_H
#include "body.h"

#define STATE_INIT  4
#define STATE_STAY  0
#define STATE_START 1
#define STATE_WALK  2
#define STATE_STOP  3

#define PHASE_0 0
#define PHASE_1 1
#define PHASE_2 2
#define PHASE_3 3

struct LegsPos
{
    int _legspos[4];
};

class StepPlanner
{
public:
    StepPlanner();
    friend ostream& operator<<(ostream& os, const StepPlanner p);
    LegsPos GetNextStep();
    void Run();
    void Stop();
private:
    Body _b;
    int _new_state;
    int _state;
    int _phase;
    LegsPos NextStepWalk();
    LegsPos NextStepStart();
    LegsPos NextStepStop();
    LegsPos NextStepInit();
    void NextPhase();
};

#endif // STEPPLANNER_H
