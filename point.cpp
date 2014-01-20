#include "point.h"

Point::Point()
    :_x(0)
    ,_y(0)
    ,_z(0)
{
    _description=new char[POINT_DESCRIPTION_SIZE];
}

ostream& operator<<(ostream& os, const Point p)
{
    if(strlen(p.GetDescription())>0)os<<p.GetDescription()<<":\t";
    os<<"x="<<p.GetX()<<"\ty="<<p.GetY()<<"\tz="<<p.GetZ()<<"\n";
    return os;
}
