#ifndef LOCKMECHANISM_H
#define LOCKMECHANISM_H

#include <Arduino.h>
#include <Servo.h>

// Class that controls the servo motor lock
class LockMechanism {

private:

    Servo servo;      // Servo object
    int servoPin;     // Arduino pin connected to servo
    int lockedAngle;  // Angle for locked position
    int unlockedAngle;// Angle for unlocked position

public:

    // Constructor
    LockMechanism(int pin, int lockAngle = 0, int unlockAngle = 90);

    // Initializes servo
    void begin();

    // Rotate servo to locked position
    void lock();

    // Rotate servo to unlocked position
    void unlock();
};

#endif