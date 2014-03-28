#include "body.h"
#include "config.h"
#include "math.h"

Body::Body()
    :_clearance(150)
    ,_tilt(0.0)
{
    _legs=new Leg[4];
    _legs[0].SetDescription("right back");
    _legs[0].SetOrigin(Point(RIGHT_BACK_ORIGIN_X,RIGHT_BACK_ORIGIN_Y,RIGHT_BACK_ORIGIN_Z));
    _legs[0].SetLinksLen(RIGHT_BACK_LINK_1_LEN,RIGHT_BACK_LINK_2_LEN);
    _legs[1].SetDescription("right front");
    _legs[1].SetOrigin(Point(RIGHT_FRONT_ORIGIN_X,RIGHT_FRONT_ORIGIN_Y,RIGHT_FRONT_ORIGIN_Z));
    _legs[1].SetLinksLen(RIGHT_FRONT_LINK_1_LEN,RIGHT_FRONT_LINK_2_LEN);
    _legs[2].SetDescription("left back");
    _legs[2].SetOrigin(Point(LEFT_BACK_ORIGIN_X,LEFT_BACK_ORIGIN_Y,LEFT_BACK_ORIGIN_Z));
    _legs[2].SetLinksLen(LEFT_BACK_LINK_1_LEN,LEFT_BACK_LINK_2_LEN);
    _legs[3].SetDescription("left front");
    _legs[3].SetOrigin(Point(LEFT_FRONT_ORIGIN_X,LEFT_FRONT_ORIGIN_Y,LEFT_FRONT_ORIGIN_Z));
    _legs[3].SetLinksLen(LEFT_FRONT_LINK_1_LEN,LEFT_FRONT_LINK_2_LEN);
    _yaw.SetNullPWM(1500);
    _yaw.SetMinMaxPWM(1300,1700);
    _yaw.SetCalibrationValue(M_PI/2.0,600);
}

ostream& operator<<(ostream& os, const Body b)
{
    os<<"Dog body is"<<endl;
    for(int i=0;i<4;i++)
        os<<b._legs[i];
    return os;
}

void Body::UpdateLegsOrigin()
{

}
