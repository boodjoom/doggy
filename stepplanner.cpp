#include "stepplanner.h"
#include "stdlib.h"

#define OK 0

StepPlanner::StepPlanner()
{
    _action=ACTION_NONE;
    _new_action=ACTION_NONE;
    _direction=DIRECTION_FORWARD;
    _phase=PHASE_0;
}

ostream& operator<<(ostream& os, const StepPlanner p)
{
    os<<"Action="<<p._action<<" Phase="<<p._phase<<" Dir="<<p._direction<<" NewAct="<<p._new_action<<endl;
    return os;
}

StepMap StepPlanner::NextStepWalk(int direction)
{
    if(direction==DIRECTION_FORWARD)
        return NextStepForward();
    else return NextStepBackward();
}

StepMap StepPlanner::NextStepForward()
{
    StepMap lp;
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

StepMap StepPlanner::NextStepBackward()
{
    StepMap lp;
    char tmp[4];
    switch(_phase)
    {
    case PHASE_0:
        strcpy(tmp,WALK_2);
        break;
    case PHASE_1:
        strcpy(tmp,WALK_1);
        break;
    case PHASE_2:
        strcpy(tmp,WALK_0);
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

StepMap StepPlanner::NextStepStart(int direction)
{
    if(direction==DIRECTION_FORWARD)
        return NextStepStartF();
    else return NextStepStartB();
}

StepMap StepPlanner::NextStepStartF()
{
    StepMap lp;
    char tmp[4];
    switch(_phase)
    {
    case PHASE_0:
        strcpy(tmp,FORWARD_0);
        break;
    case PHASE_1:
        strcpy(tmp,FORWARD_1);
        break;
    case PHASE_2:
        strcpy(tmp,FORWARD_2);
        break;
    case PHASE_3:
        strcpy(tmp,FORWARD_3);
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

StepMap StepPlanner::NextStepStartB()
{
    StepMap lp;
    char tmp[4];
    switch(_phase)
    {
    case PHASE_0:
        strcpy(tmp,BACKWARD_0);
        break;
    case PHASE_1:
        strcpy(tmp,BACKWARD_1);
        break;
    case PHASE_2:
        strcpy(tmp,BACKWARD_2);
        break;
    case PHASE_3:
        strcpy(tmp,BACKWARD_3);
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

StepMap StepPlanner::NextStepStop(int direction)
{
    if(direction==DIRECTION_FORWARD)
        return NextStepStopF();
    else return NextStepStopB();
}

StepMap StepPlanner::NextStepStopF()
{
    StepMap lp;
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

StepMap StepPlanner::NextStepStopB()
{
    StepMap lp;
    char tmp[4];
    switch(_phase)
    {
    case PHASE_0:
        strcpy(tmp,STOP_3);
        break;
    case PHASE_1:
        strcpy(tmp,STOP_2);
        break;
    case PHASE_2:
        strcpy(tmp,STOP_1);
        break;
    case PHASE_3:
        strcpy(tmp,STOP_0);
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

StepMap StepPlanner::NextStepInit()
{
    return NextStepStopF();
}

StepMap StepPlanner::Stay()
{
    StepMap lp;
    char tmp[4];
    strcpy(tmp,STAY);
    char n[2];
    n[1]='\0';
    for(int i=0;i<4;i++)
    {
        n[0]=tmp[i];
        lp._legspos[i]=atoi(n);
    }
    return lp;
}

StepMap StepPlanner::GetNextStep()
{
    StepMap lp;
    switch(_action)
    {
        case ACTION_STAY:
            lp=Stay();
            break;
        case ACTION_INIT:
            lp=NextStepInit();
            break;
        case ACTION_START:
            lp=NextStepStart(_direction);
            break;
        case ACTION_WALK:
            lp=NextStepWalk(_direction);
            break;
        case ACTION_STOP:
            lp=NextStepStop(_direction);
            break;
    }
    NextPhase();
    UpdateAction();
    return lp;
}

void StepPlanner::Init()
{
    if(_action==ACTION_NONE)
        _action=ACTION_INIT;
}

int StepPlanner::Run(int direction)
{
    if(_action!=ACTION_WALK)
    {
        _new_action=ACTION_START;
        _direction=direction;
    }
    return OK;
}

int StepPlanner::Stop()
{
    if(_action==ACTION_WALK)
        _new_action=ACTION_STOP;
    return OK;
}

void StepPlanner::NextPhase()
{
    _phase++;
    if(_phase>3 || _action==ACTION_STAY || _action==ACTION_NONE)
        _phase=PHASE_0;
}

void StepPlanner::UpdateAction()
{
    if(_phase==PHASE_0)
    {
        if(_new_action!=ACTION_NONE)
        {
            _action=_new_action;
            _new_action=ACTION_NONE;
        } else
        {
            switch(_action)
            {
            case ACTION_STAY:
                return;
            case ACTION_INIT:
            case ACTION_STOP:
                _action=ACTION_STAY;
                break;
            case ACTION_START:
                _action=ACTION_WALK;
                break;
            }
        }
    }
}

ostream& operator <<(ostream& os, const StepMap p)
{
    for(int i=0;i<4;i++)
        cout<<p._legspos[i];
    cout<<endl;
    return os;
}

bool StepMap::operator ==(StepMap &sm)
{
    for(int i=0;i<4;i++)
        if(_legspos[i]!=sm._legspos[i] && _legspos[i]!=0 && sm._legspos[i]!=0)
            return false;
    return true;
}

StepMap &StepMap::operator =(StepMap sm)
{
    for(int i=0;i<4;i++)
        this->_legspos[i]=sm._legspos[i];
    return *this;
}
