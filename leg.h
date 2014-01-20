#ifndef LEG_H
#define LEG_H

#include "point.h"
#include "link.h"
#include "utils.h"
#include "config.h"

class Leg_angles
{
public:
    Leg_angles(){}
    double GetFirst(bool deg=false) const{return GetAngle(0,deg);}
    double GetSecond(bool deg=false) const{return GetAngle(1,deg);}
    double GetAngle(int num, bool deg=false)const{if(deg)return _angles[num]*180.0/M_PI;else return _angles[num];}
    void SetAngle(int num, double angle){_angles[num]=angle;}
    Leg_angles& operator=(const Link& l);
private:
    double _angles[LINK_COUNT_PER_LEG];
};

class Leg
{
public:
    Leg();
    void Serialize();
    void SetDescription(const char* description);
    const char* GetDescription()const{return _description;}
    Leg_angles GetAgles(Point p);
    void SetOrigin(Point p){_origin=p;}
    void SetLinksLen(double first_link_len,double second_link_len){_links[0].SetLength(first_link_len);_links[1].SetLength(second_link_len);}
private:
    Point _origin;
    Link* _links;
    friend ostream& operator<<(ostream& os, const Leg p);
    char* _description;
};

#endif // LEG_H
