#include "stepplanner.h"

StepPlanner::StepPlanner()
{

}

ostream& operator<<(ostream& os, const StepPlanner p)
{
    os<<p._b;
    return os;
}
