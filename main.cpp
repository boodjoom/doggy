#include <iostream>
#include "point.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Point p1(1,2,3);
    Point p2(4,5,6);
    Point p3=p1+p2;
    p3.SetDescription("test one");
    std::cout<<p3;
    return 0;
}

