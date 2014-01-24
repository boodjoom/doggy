#include "leg.h"
#include "utils.h"
#include "math.h"

#define ERROR_POINT_IS_UNREACHEBLE 1
#define OK

Leg::Leg()
{
    _description=new char[LEG_DESCRIPTION_SIZE];
    memset(_description,'\0',LEG_DESCRIPTION_SIZE);
    _links = new Link[LINK_COUNT_PER_LEG];
    for(int i=0;i<LINK_COUNT_PER_LEG;i++)
        _links[i].SetNum(i);
    _origin.SetDescription("Origin");
}

Leg_angles& Leg_angles::operator=(const Link& l)
{
    if(l.GetNum()<LINK_COUNT_PER_LEG)
        SetAngle(l.GetNum(),l.GetAngle());
    return *this;
}

ostream& operator<<(ostream& os, const Leg p)
{
    os<<"Leg "<<p._description<<endl;
    os<<p._origin;
    for(int i=0;i<LINK_COUNT_PER_LEG;i++)
        os<<p._links[i];
    return os;
}

void Leg::SetDescription(const char *description)
{
    if(strlen(description)<LEG_DESCRIPTION_SIZE)
        strcpy(_description,description);
}

Leg_angles Leg::GetAgles(Point p)
{
    Utils u;
    Leg_angles la;
    ccirez cci = u.cci(_origin,_links[0].GetLength(),p,_links[1].GetLength());
    if(cci.count==2)
    {
        double fi1=atan2(cci.points[0].GetY()-_origin.GetY(),cci.points[0].GetX()-_origin.GetX());
        double fi2=atan2(cci.points[1].GetY()-_origin.GetY(),cci.points[1].GetX()-_origin.GetX());
        if(fi1>fi2)
        {
            la.SetAngle(0,fi1);
            la.SetAngle(1,atan2(p.GetY()-cci.points[0].GetY(),p.GetX()-cci.points[0].GetX()));
        }
        else
        {
            la.SetAngle(0,fi2);
            la.SetAngle(1,atan2(p.GetY()-cci.points[1].GetY(),p.GetX()-cci.points[1].GetX()));
        }
    } else if(cci.count==1)
    {
        la.SetAngle(0,atan2(cci.points[0].GetY()-_origin.GetY(),cci.points[0].GetX()-_origin.GetX()));
        la.SetAngle(1,atan2(p.GetY()-cci.points[0].GetY(),p.GetX()-cci.points[0].GetX()));
    } else la.SetFail();
    return la;
}

int Leg::MoveLegToPoint(Point p, int duration_ms)
{
    Leg_angles la=GetAgles(p);
    if(la.IsFail())
        return ERROR_POINT_IS_UNREACHEBLE;
    _links[0].MoveToAngle(la.GetFirst(),duration_ms);
    _links[1].MoveToAngle(la.GetSecond(),duration_ms);
    _current=p;
}
