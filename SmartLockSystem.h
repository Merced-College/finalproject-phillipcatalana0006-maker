#ifndef SMARTLOCKSYSTEM_H
#define SMARTLOCKSYSTEM_H

#include <Arduino.h>
#include "LockMechanism.h"
#include "AlarmSystem.h"
#include "MemoryManager.h"

class SmartLockSystem {
private:
    LockMechanism lockMechanism;
    AlarmSystem alarmSystem;
    MemoryManager memoryManager;

    String storedPassword;
    int failedAttempts;
    const int maxAttempts = 3;

    bool waitingForNewPassword;
    bool unlocked;
    unsigned long unlockStartTime;
    const unsigned long unlockDuration = 5000;

public:
    SmartLockSystem();

    void begin();
    void processInput(String input);
    void update();

private:
    void checkPassword(const String& input);
    void changePassword(const String& newPassword);
    void unlockSystem();
    void lockSystem();
};

#endif