#include "point.h"

Point::Point()
{
    m_description=new char[DESCRIPTION_SIZE];
}

ostream& operator<<(ostream& os, const Point p)
{
    if(strlen(p.GetDescription())>0)os<<p.GetDescription()<<":"<<endl;
    os<<"x="<<p.GetX()<<"\ty="<<p.GetY()<<"\tz="<<p.GetZ()<<"\n";
    return os;
}
