#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_DISABLED 0
#define MOTOR_ENABLED 1

class Motor
{
public:
    Motor();
    void TurnOff();
    void TurnOn();
    int GetStatus(){return _status;}
private:
    int _status;
};

#endif // MOTOR_H
