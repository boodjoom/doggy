#include "motor.h"

Motor::Motor()
{
    TurnOff();
}

void Motor::TurnOff()
{
    _status=MOTOR_DISABLED;
}

void Motor::TurnOn()
{
    _status=MOTOR_ENABLED;
}
