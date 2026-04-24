#ifndef SMARTLOCKSYSTEM_H
#define SMARTLOCKSYSTEM_H

#include <Arduino.h>

// Include all subsystem classes used by the smart lock
#include "LockMechanism.h"
#include "AlarmSystem.h"
#include "MemoryManager.h"
#include "KeypadInput.h"
#include "DisplayManager.h"

// Main class that controls the entire smart lock system
class SmartLockSystem {

private:

    // Hardware control classes
    LockMechanism lockMechanism;     // Controls the servo motor
    AlarmSystem alarmSystem;         // Controls buzzer and LEDs
    MemoryManager memoryManager;     // Handles EEPROM password storage
    KeypadInput keypadInput;         // Reads keypad button presses
    DisplayManager displayManager;   // Controls the LCD display

    // Stores the saved password
    String storedPassword;

    // Stores the password currently being typed
    String enteredPassword;

    // Tracks number of incorrect attempts
    int failedAttempts;

    // Maximum attempts before alarm triggers
    const int maxAttempts = 3;

    // Used when the user is changing the password
    bool waitingForNewPassword;

    // Tracks whether the lock is currently open
    bool unlocked;

    // Time tracking for auto-lock feature
    unsigned long unlockStartTime;

    // Time before system auto-locks again
    const unsigned long unlockDuration = 5000;

public:

    // Constructor
    SmartLockSystem();

    // Initializes the entire system
    void begin();

    // Runs continuously and checks for keypad input
    void update();

private:

    // Processes keypad button presses
    void handleKey(char key);

    // Compares entered password to stored password
    void checkPassword();

    // Updates stored password
    void changePassword();

    // Unlocks the servo mechanism
    void unlockSystem();

    // Locks the servo mechanism
    void lockSystem();
};

#endif