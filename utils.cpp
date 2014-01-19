#include "utils.h"

Utils::Utils()
{
}

double Utils::dist(Point p1, Point p2)
{
    Point p=p2-p1;
    return sqrt(pow(p.GetX(),2)+pow(p.GetY(),2));
}

//m - tolerance of distance, i.e. if distance between border of circles between -nMargin/2 .. +nMargin/2
//            it counts as one point
//www.litunovskiy.com/gamedev/intersection_of_two_circles/
ccirez Utils::cci(Point p1,double r1,Point p2,double r2, double m)
{
    ccirez rez;
    rez.count=0;
    double d = dist(p1, p2);
    if (fabs(d - fabs(r1 - r2)) < m / 2.0)
    {
        double nSign = (r1 - r2)/fabs(r1-r2);
        double nDelta = (d - fabs(r1 - r2)) / 2.0;
        rez.count=1;
        rez.points[0].SetX(p1.GetX() + (r1 - nDelta) * (p2.GetX() - p1.GetX()) / d * nSign);
        rez.points[0].SetY(p1.GetY() + (r1 - nDelta) * (p2.GetY() - p1.GetY()) / d * nSign);
    }
    else if (fabs(d - (r1 + r2)) < m / 2.0)
    {
        rez.count=1;
        double nDelta = (d - fabs(r1 + r2)) / 2.0;
        rez.points[0].SetX(p1.GetX() + (r1 + nDelta) * (p2.GetX() - p1.GetX()) / d);
        rez.points[0].SetY(p1.GetY() + (r1 + nDelta) * (p2.GetY() - p1.GetY()) / d);
    }
    else if (d < r1 + r2 && d > fabs(r1 - r2))
    {
        rez.count = 2;
        double b = (r2 * r2 - r1 * r1 + d * d) / (2.0 * d);
        double a = d - b;
        double h = sqrt(r1 * r1 - a * a);
        double x0 = p1.GetX() + a / d * (p2.GetX() - p1.GetX());
        double y0 = p1.GetY() + a / d * (p2.GetY() - p1.GetY());
        rez.points[0].SetX(x0 + h / d * (p2.GetY() - p1.GetY()));
        rez.points[0].SetY(y0 - h / d * (p2.GetX() - p1.GetX()));
        rez.points[1].SetX(x0 - h / d * (p2.GetY() - p1.GetY()));
        rez.points[1].SetY(y0 + h / d * (p2.GetX() - p1.GetX()));
    }
    return rez;
}
