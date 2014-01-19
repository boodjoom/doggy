#include "link.h"

Link::Link(int num)
    :_link_num(num)
{
    Link();
}

Link::Link()
    :_cx(0.0)
    ,_cy(0.0)
    ,_cz(0.0)
    ,_fi(0.0)
{
}

ostream& operator<<(ostream& os, const Link p)
{
    os<<"Link id="<<p.GetNum()<<"\tlen="<<p.GetLength()<<"\tfi="<<p.GetAngle()<<endl;
    return os;
}

