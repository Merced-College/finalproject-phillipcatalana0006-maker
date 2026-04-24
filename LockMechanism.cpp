#include "LockMechanism.h"

// Constructor sets servo pin and rotation angles
LockMechanism::LockMechanism(int pin, int lockAngle, int unlockAngle) {
    servoPin = pin;
    lockedAngle = lockAngle;
    unlockedAngle = unlockAngle;
}

// Attach servo to Arduino pin
void LockMechanism::begin() {
    servo.attach(servoPin);

    // Start locked
    servo.write(lockedAngle);
}

// Rotate servo to locked position
void LockMechanism::lock() {
    servo.write(lockedAngle);
}

// Rotate servo to unlocked position
void LockMechanism::unlock() {
    servo.write(unlockedAngle);
}