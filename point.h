#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string.h>
using namespace std;
#define DESCRIPTION_SIZE 32
class Point
{
public:
    Point();
    Point(double x, double y, double z,char* description=NULL){m_x=x;m_y=y;m_z=z;m_description=new char[DESCRIPTION_SIZE];if(description!=NULL)strcpy(m_description,description);else memset(m_description,'\0',DESCRIPTION_SIZE);}
    double GetX() const{return m_x;}
    double GetY() const{return m_y;}
    double GetZ() const{return m_z;}
    void SetX(double x){m_x=x;}
    void SetY(double y){m_y=y;}
    void SetZ(double z){m_z=z;}
    double* GetXYZ(){double* vp=new double[3];vp[0]=m_x;vp[1]=m_y;vp[2]=m_z;return vp;}
    void SetXYZ(double* vp){m_x=vp[0];m_y=vp[1];m_z=vp[2];}
    Point operator+ (Point& p){Point tp(m_x+p.GetX(),m_y+p.GetY(),m_z+p.GetZ());return tp;}
    friend ostream& operator<<(ostream& os, const Point p);
    char* GetDescription() const{return m_description;}
    void SetDescription(char * description){strcpy(m_description,description);}
private:
    double m_x;
    double m_y;
    double m_z;
    char* m_description;
};

#endif // POINT_H
