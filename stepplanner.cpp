#include "stepplanner.h"
#include "stdlib.h"

StepPlanner::StepPlanner()
{
    _state=STATE_INIT;
    _phase=PHASE_0;
}

ostream& operator<<(ostream& os, const StepPlanner p)
{
    os<<p._b;
    return os;
}

LegsPos StepPlanner::NextStepWalk()
{
    LegsPos lp;
    char tmp[4];
    switch(_phase)
    {
    case PHASE_0:
        strcpy(tmp,WALK_0);
        break;
    case PHASE_1:
        strcpy(tmp,WALK_1);
        break;
    case PHASE_2:
        strcpy(tmp,WALK_2);
        break;
    case PHASE_3:
        strcpy(tmp,WALK_3);
        break;
    }
    char n[2];
    n[1]='\0';
    for(int i=0;i<4;i++)
    {
        n[0]=tmp[i];
        lp._legspos[i]=atoi(n);
    }
    return lp;
}

LegsPos StepPlanner::NextStepStart()
{
    LegsPos lp;
    char tmp[4];
    switch(_phase)
    {
    case PHASE_0:
        strcpy(tmp,START_0);
        break;
    case PHASE_1:
        strcpy(tmp,START_1);
        break;
    case PHASE_2:
        strcpy(tmp,START_2);
        break;
    case PHASE_3:
        strcpy(tmp,START_3);
        break;
    }
    char n[2];
    n[1]='\0';
    for(int i=0;i<4;i++)
    {
        n[0]=tmp[i];
        lp._legspos[i]=atoi(n);
    }
    return lp;
}

LegsPos StepPlanner::NextStepStop()
{
    LegsPos lp;
    char tmp[4];
    switch(_phase)
    {
    case PHASE_0:
        strcpy(tmp,STOP_0);
        break;
    case PHASE_1:
        strcpy(tmp,STOP_1);
        break;
    case PHASE_2:
        strcpy(tmp,STOP_2);
        break;
    case PHASE_3:
        strcpy(tmp,STOP_3);
        break;
    }
    char n[2];
    n[1]='\0';
    for(int i=0;i<4;i++)
    {
        n[0]=tmp[i];
        lp._legspos[i]=atoi(n);
    }
    return lp;
}

LegsPos StepPlanner::NextStepInit()
{
    return NextStepStop();
}

LegsPos StepPlanner::GetNextStep()
{
    LegPos lp;
    switch(_state)
    {
        case STATE_INIT:
            lp=NextStepInit();
            break;
        case STATE_START:
            lp=NextStepStart();
            break;
        case STATE_WALK:
            lp=NextStepWalk();
            break;
        case STATE_STOP:
            lp=NextStepStop();
            break;
    }
    NextPhase();
    return lp;
}

void StepPlanner::NextPhase()
{
    _phase++;
    if(_phase>3)
        _phase=0;
}
