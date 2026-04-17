#ifndef LOCKMECHANISM_H
#define LOCKMECHANISM_H

#include <Arduino.h>
#include <Servo.h>

class LockMechanism {
private:
    Servo servo;
    int servoPin;
    int lockedAngle;
    int unlockedAngle;

public:
    LockMechanism(int pin, int lockAngle = 0, int unlockAngle = 90);

    void begin();
    void lock();
    void unlock();
};

#endif