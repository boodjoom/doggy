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
    w.Init();
    do
    {
        cout<<w;
        w.Execute();
        cin>>c;
        if(c=='w')
            w.Forward();
        else if(c=='s')
            w.BackWard();
        else if(c=='a')
            w.Stop();
    }
    while(c!='x');
    return 0;
}
