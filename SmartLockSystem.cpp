#include "SmartLockSystem.h"

// Constructor initializes hardware pins and system states
SmartLockSystem::SmartLockSystem()
    : lockMechanism(9, 0, 90),        // Servo on pin 9
      alarmSystem(10, 13, A0),        // Buzzer + LEDs
      failedAttempts(0),
      waitingForNewPassword(false),
      unlocked(false),
      unlockStartTime(0) {
}

// Initializes all hardware components
void SmartLockSystem::begin() {

    // Start each subsystem
    lockMechanism.begin();
    alarmSystem.begin();
    keypadInput.begin();
    displayManager.begin();

    // Load password from EEPROM
    storedPassword = memoryManager.loadPassword();

    // If EEPROM is empty, create default password
    if (storedPassword.length() == 0) {
        storedPassword = "1234";
        memoryManager.savePassword(storedPassword);
    }

    enteredPassword = "";

    // Ensure system starts locked
    lockSystem();

    // Show initial message on LCD
    displayManager.showMessage("Enter Password", "");
}

// Main system loop
void SmartLockSystem::update() {

    // Read key from keypad
    char key = keypadInput.getKey();

    // If a key was pressed, process it
    if (key) {
        handleKey(key);
    }

    // Auto-lock system after unlock timer expires
    if (unlocked && millis() - unlockStartTime >= unlockDuration) {
        lockSystem();
        displayManager.showMessage("Auto Locked", "");
        delay(1000);
        displayManager.showMessage("Enter Password", "");
    }
}

// Handles keypad input logic
void SmartLockSystem::handleKey(char key) {

    // Make a short beep for every key press
    alarmSystem.beepKeypress();

    // If user is entering a new password
    if (waitingForNewPassword) {

        if (key == '#') {
            changePassword();
        }

        else if (key == '*') {
            enteredPassword = "";
            displayManager.showMessage("New Pass Cleared", "");
        }

        else {
            enteredPassword += key;
            displayManager.showMessage("New Password:", enteredPassword);
        }

        return;
    }

    // Enter password change mode
    if (key == 'A') {
        enteredPassword = "";
        waitingForNewPassword = true;
        displayManager.showMessage("Change Password", "Enter New Pass");
        return;
    }

    // Clear input
    if (key == '*') {
        enteredPassword = "";
        displayManager.showMessage("Cleared", "");
        delay(500);
        displayManager.showMessage("Enter Password", "");
        return;
    }

    // Submit password
    if (key == '#') {
        checkPassword();
        return;
    }

    // Add key to password string
    enteredPassword += key;

    // Display entered digits
    displayManager.showMessage("Password:", enteredPassword);
}

// Checks if entered password matches stored password
void SmartLockSystem::checkPassword() {

    // If correct password entered
    if (enteredPassword == storedPassword) {

        displayManager.showMessage("Access Granted", "");

        alarmSystem.beepSuccess();

        unlockSystem();

        failedAttempts = 0;
    }

    // If incorrect password
    else {

        failedAttempts++;

        alarmSystem.beepShort();

        displayManager.showMessage("Wrong Password", "Try Again");

        // Trigger alarm if too many attempts
        if (failedAttempts >= maxAttempts) {
            displayManager.showMessage("ALARM!", "Too Many Tries");
            alarmSystem.triggerAlarm();
            failedAttempts = 0;
        }

        delay(1000);

        if (!unlocked) {
            displayManager.showMessage("Enter Password", "");
        }
    }

    enteredPassword = "";
}

// Saves new password into EEPROM
void SmartLockSystem::changePassword() {

    if (enteredPassword.length() == 0) {

        displayManager.showMessage("Empty Password", "Not Saved");

        delay(1000);
    }

    else {

        storedPassword = enteredPassword;

        memoryManager.savePassword(storedPassword);

        alarmSystem.beepSuccess();

        displayManager.showMessage("Password Saved", "");

        delay(1000);
    }

    enteredPassword = "";

    waitingForNewPassword = false;

    displayManager.showMessage("Enter Password", "");
}

// Unlocks the servo and records time
void SmartLockSystem::unlockSystem() {

    lockMechanism.unlock();

    alarmSystem.showUnlocked();

    unlocked = true;

    unlockStartTime = millis();
}

// Locks the servo again
void SmartLockSystem::lockSystem() {

    lockMechanism.lock();

    alarmSystem.showLocked();

    unlocked = false;
}