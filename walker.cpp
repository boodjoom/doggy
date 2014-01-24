#include "walker.h"

Walker::Walker()
    :StepPlanner()
    ,_step_length(100)
    ,_delay_ms(100)
    ,_step_duration_ms(1000)
    ,_the_body(NULL)
    ,_counter(0)
    ,_c_leg_up(0)
    ,_c_leg_down(0)
{
}

int Walker::Execute()
{
    StepMap sm;
    sm=GetNextStep();
    if(sm==_prev_map)
        return 0;
    if(_counter==0)
        Phase0(sm);
    else if(_counter==_c_leg_up)
        Phase1(sm);
    else if(_counter==_c_leg_down)
        Phase2(sm);
    IncCounter();
    _prev_map=sm;
    return 1;
}

void Walker::UpdateCValues()
{
    //duration=leg_up+leg_fly+leg_down;
    double prop=(double)_step_length/(2.0*(double)_step_height);
    prop=(double)_step_height/(double)_step_length;
    prop=1.0+2.0*prop;
    int leg_fly_ms=(int)(((double)_step_duration_ms/prop)+0.5);
   _c_leg_up=(_step_duration_ms-leg_fly_ms)/2;
   _c_leg_down=_c_leg_up+leg_fly_ms;
}

void Walker::IncCounter()
{
    _counter+=_delay_ms;
    if(_counter>_step_duration_ms)
        _counter=0;
}

void Walker::MoveBody(int leg, int new_pos)
{
    _the_body->GetLeg(leg)->MoveLegToPoint(PosToPoint(leg,new_pos),_step_duration_ms);
}

Point Walker::PosToPoint(int leg, int pos)
{
    Point rez=_the_body->GetLeg(leg)->GetOrigin();
    rez.SetY(rez.GetY()+_the_body->GetClearance());
    rez.SetX(rez.GetX()-_step_length/2.0+((double)pos-1.0)*(_step_length/6.0));
    return rez;
}

void Walker::MoveLegUp(int leg)
{
    Point p = _the_body->GetLeg(leg)->GetCurrentPoint();
    p.SetY(p.GetY()-_step_height);
    _the_body->GetLeg(leg)->MoveLegToPoint(p,_c_leg_up);
}

void Walker::MoveLeg(int leg, int pos)
{
    Point p = PosToPoint(leg,pos);
    p.SetY(_the_body->GetLeg(leg)->GetCurrentPoint().GetY());
    _the_body->GetLeg(leg)->MoveLegToPoint(p,_c_leg_down-_c_leg_up);
}

void Walker::MoveLegDown(int leg)
{
    Point p = _the_body->GetLeg(leg)->GetCurrentPoint();
    p.SetY(p.GetY()+_step_height);
    _the_body->GetLeg(leg)->MoveLegToPoint(p,_c_leg_up);
}

void Walker::Phase0(StepMap sm)
{
    if(_direction==DIRECTION_FORWARD)
    {
        for(int i=0;i<4;i++)
            if(sm._legspos[i]<_prev_map._legspos[i])
                MoveBody(i,sm._legspos[i]);
            else
            {
                MoveLegUp(i);
            }

    }
    else
    {
        for(int i=0;i<4;i++)
            if(sm._legspos[i]>_prev_map._legspos[i])
                MoveBody(i,sm._legspos[i]);
            else
            {
                MoveLegUp(i);
            }

    }
}

void Walker::Phase1(StepMap sm)
{
    if(_direction==DIRECTION_FORWARD)
    {
        for(int i=0;i<4;i++)
            if(sm._legspos[i]>_prev_map._legspos[i])
            {
                MoveLeg(i,sm._legspos[i]);
            }

    }
    else
    {
        for(int i=0;i<4;i++)
            if(sm._legspos[i]<_prev_map._legspos[i])
            {
                MoveLeg(i,sm._legspos[i]);
            }

    }
}

void Walker::Phase2(StepMap sm)
{
    if(_direction==DIRECTION_FORWARD)
    {
        for(int i=0;i<4;i++)
            if(sm._legspos[i]>_prev_map._legspos[i])
            {
                MoveLegDown(i);
            }

    }
    else
    {
        for(int i=0;i<4;i++)
            if(sm._legspos[i]<_prev_map._legspos[i])
            {
                MoveLegDown(i);
            }
    }
}

int Walker::Forward()
{
    return Run(DIRECTION_FORWARD);
}

int Walker::BackWard()
{
    return Run(DIRECTION_BACKWARD);
}
