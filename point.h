#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string.h>
#include "config.h"

using namespace std;

class Point
{
public:
    Point();
    Point(double x, double y, double z,char* description=NULL){_x=x;_y=y;_z=z;_description=new char[POINT_DESCRIPTION_SIZE];if(description!=NULL)strcpy(_description,description);else memset(_description,'\0',POINT_DESCRIPTION_SIZE);}
    double GetX() const{return _x;}
    double GetY() const{return _y;}
    double GetZ() const{return _z;}
    void SetX(double x){_x=x;}
    void SetY(double y){_y=y;}
    void SetZ(double z){_z=z;}
    double* GetXYZ(){double* vp=new double[3];vp[0]=_x;vp[1]=_y;vp[2]=_z;return vp;}
    void SetXYZ(double* vp){_x=vp[0];_y=vp[1];_z=vp[2];}
    Point operator+ (Point& p){Point tp(_x+p.GetX(),_y+p.GetY(),_z+p.GetZ());return tp;}
    Point operator- (Point& p){Point tp(_x-p.GetX(),_y-p.GetY(),_z-p.GetZ());return tp;}
    Point& operator=(Point& p){_x=p.GetX(); _y=p.GetY(); _z=p.GetZ(); return *this;}
    friend ostream& operator<<(ostream& os, const Point p);
    char* GetDescription() const{return _description;}
    void SetDescription(const char * description){strcpy(_description,description);}
private:
    double _x;
    double _y;
    double _z;
    char* _description;
};

#endif // POINT_H
