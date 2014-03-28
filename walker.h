#ifndef WALKER_H
#define WALKER_H

#include "stepplanner.h"
#include "body.h"

class Walker : public StepPlanner
{
public:
    Walker();
    int Forward();
    int BackWard();
    int SetDelay(int ms){_delay_ms=ms;return 0;}
    int Execute();
    void SetStepLength(int step_length){_step_length=step_length;}
    void SetStepDuration(int step_duration_ms){_step_duration_ms=step_duration_ms;}
    void SetBody(Body& the_body){_the_body=&the_body;}
    void SetStepHeight(int step_height){_step_height=step_height;}
    void Initialize();
private:
    void UpdateCValues();
    void IncCounter();
    void MoveBody(int leg, int new_pos);
    Point PosToPoint(int leg, int pos);
    int _step_length;
    int _step_height;
    int _delay_ms;
    int _step_duration_ms;
    Body* _the_body;
    StepMap _prev_map;
    int _counter;
    int _c_leg_up;
    int _c_leg_down;
    void MoveLegUp(int leg);
    void MoveLeg(int leg, int pos);
    void MoveLegDown(int leg);
    void Phase0(StepMap sm);
    void Phase1(StepMap sm);
    void Phase2(StepMap sm);
    //void Phase3();
};

#endif // WALKER_H
