#include "LockMechanism.h"

LockMechanism::LockMechanism(int pin, int lockAngle, int unlockAngle) {
    servoPin = pin;
    lockedAngle = lockAngle;
    unlockedAngle = unlockAngle;
}

void LockMechanism::begin() {
    servo.attach(servoPin);
    servo.write(lockedAngle);
}

void LockMechanism::lock() {
    servo.write(lockedAngle);
}

void LockMechanism::unlock() {
    servo.write(unlockedAngle);
}