#ifndef UTILS_H
#define UTILS_H

#include "math.h"
#include "point.h"
#include "config.h"

struct ccirez
{
    Point points[2];
    int count;
};

class Utils
{
public:
    Utils();
    ccirez cci(Point p1,double r1,Point p2,double r2, double m=0);
    double dist(Point p1, Point p2);
};

#endif // UTILS_H
