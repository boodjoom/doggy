#include <iostream>
#include "point.h"
#include "leg.h"
#include "stepplanner.h"
#include "walker.h"
using namespace std;

int main()
{
    Walker w;
    char c;
    w.Initialize();
    Body b;
    w.SetBody(b);
    do
    {
        cout<<w;
        w.Execute();
        cout<<b;
        /*cin>>c;
        if(c=='w')
            w.Forward();
        else if(c=='s')
            w.BackWard();
        else if(c=='a')
            w.Stop();
            */
    }
    while(c!='x');
    return 0;
}
