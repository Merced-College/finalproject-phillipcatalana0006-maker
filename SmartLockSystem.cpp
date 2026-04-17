#include "SmartLockSystem.h"

SmartLockSystem::SmartLockSystem()
    : lockMechanism(9),
      alarmSystem(10, 11, 12),
      failedAttempts(0),
      waitingForNewPassword(false),
      unlocked(false),
      unlockStartTime(0) {
}

void SmartLockSystem::begin() {
    lockMechanism.begin();
    alarmSystem.begin();

    storedPassword = memoryManager.loadPassword();

    if (storedPassword.length() == 0) {
        storedPassword = "1234";
        memoryManager.savePassword(storedPassword);
    }

    lockSystem();

    Serial.println("Stored password loaded.");
    Serial.println("Default is 1234 if EEPROM was empty.");
}

void SmartLockSystem::processInput(String input) {
    if (waitingForNewPassword) {
        changePassword(input);
        waitingForNewPassword = false;
        return;
    }

    if (input.equalsIgnoreCase("CHANGE")) {
        Serial.println("Enter NEW password:");
        waitingForNewPassword = true;
        return;
    }

    if (input.equalsIgnoreCase("LOCK")) {
        lockSystem();
        Serial.println("System manually locked.");
        return;
    }

    checkPassword(input);
}

void SmartLockSystem::checkPassword(const String& input) {
    if (input == storedPassword) {
        Serial.println("Access Granted.");
        unlockSystem();
        failedAttempts = 0;
    } else {
        failedAttempts++;
        Serial.print("Wrong Password. Attempt ");
        Serial.print(failedAttempts);
        Serial.print(" of ");
        Serial.println(maxAttempts);

        alarmSystem.beepShort();

        if (failedAttempts >= maxAttempts) {
            Serial.println("Too many failed attempts. Alarm triggered.");
            alarmSystem.triggerAlarm();
            failedAttempts = 0;
        }
    }
}

void SmartLockSystem::changePassword(const String& newPassword) {
    if (newPassword.length() == 0) {
        Serial.println("Password cannot be empty.");
        return;
    }

    storedPassword = newPassword;
    memoryManager.savePassword(storedPassword);

    Serial.println("Password changed successfully.");
    alarmSystem.beepSuccess();
}

void SmartLockSystem::unlockSystem() {
    lockMechanism.unlock();
    alarmSystem.showUnlocked();
    alarmSystem.beepSuccess();
    unlocked = true;
    unlockStartTime = millis();
}

void SmartLockSystem::lockSystem() {
    lockMechanism.lock();
    alarmSystem.showLocked();
    unlocked = false;
}

void SmartLockSystem::update() {
    if (unlocked && millis() - unlockStartTime >= unlockDuration) {
        lockSystem();
        Serial.println("Auto-lock activated.");
    }
}