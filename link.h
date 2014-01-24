#ifndef LINK_H
#define LINK_H

#include <math.h>
#include <utils.h>
#include <servo.h>

class Link
{
public:
    Link();
    Link(int num);
    double GetLength() const{return _cd;}
    void SetLength(double len){_cd=len;}
    int GetNum() const{return _link_num;}
    double GetAngle() const{return _s.GetAngle();}
    void SetNum(int num) {_link_num=num;}
    friend ostream& operator<<(ostream& os, const Link p);
    int MoveToAngle(double angle,int duration){return _s.MoveToAngle(angle,duration);}
private:
    int _link_num;
    double _cd;
    Servo _s;
};

#endif // LINK_H
