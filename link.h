#ifndef LINK_H
#define LINK_H

#include <math.h>
#include <utils.h>

class Link
{
public:
    Link();
    Link(int num);
    double GetLength() const{return sqrt(pow(_cx,2)+pow(_cy,2)+pow(_cz,2));}
    int GetNum() const{return _link_num;}
    double GetAngle() const{return _fi;}
    void SetNum(int num) {_link_num=num;}
    friend ostream& operator<<(ostream& os, const Link p);
    void SetAngle(double angle){_fi=angle;}
private:
    int _link_num;
    double _cx;
    double _cy;
    double _cz;
    double _fi;
};

#endif // LINK_H