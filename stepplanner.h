#ifndef STEPPLANNER_H
#define STEPPLANNER_H
#include "body.h"

#define ACTION_INIT  4
#define ACTION_STAY  0
#define ACTION_START 1
#define ACTION_WALK  2
#define ACTION_STOP  3
#define ACTION_NONE  5

#define DIRECTION_FORWARD 0
#define DIRECTION_BACKWARD 1

#define PHASE_0 0
#define PHASE_1 1
#define PHASE_2 2
#define PHASE_3 3

class StepMap
{
public:
    StepMap(){for(int i=0;i<4;i++)_legspos[i]=0;}
    friend ostream& operator<<(ostream& os, const StepMap p);
    bool operator ==(StepMap& sm);
    StepMap& operator=(StepMap sm);
    int _legspos[4];
};

class StepPlanner
{
public:
    StepPlanner();
    friend ostream& operator<<(ostream& os, const StepPlanner p);
    void Init();
    int Stop();
    //int GetStatus();
protected:
    int _direction;
    int Run(int direction=DIRECTION_FORWARD);
    StepMap GetNextStep();
private:
    int _new_action;
    int _action;
    //int _status;
    int _phase;
    void UpdateAction();
    StepMap NextStepWalk(int direction);
    StepMap NextStepForward();
    StepMap NextStepBackward();
    StepMap NextStepStart(int direction);
    StepMap NextStepStartF();
    StepMap NextStepStartB();
    StepMap NextStepStop(int direction);
    StepMap NextStepStopF();
    StepMap NextStepStopB();
    StepMap NextStepInit();
    StepMap Stay();
    void NextPhase();
};

#endif // STEPPLANNER_H
