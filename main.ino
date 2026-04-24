// Include the main Smart Lock system controller
#include "SmartLockSystem.h"

// Create a SmartLockSystem object that will control everything
SmartLockSystem smartLock;

// Arduino setup function runs once when the board starts
void setup() {

    // Initialize the smart lock system
    // This sets up the keypad, LCD display, servo motor, buzzer, and memory
    smartLock.begin();
}

// Arduino loop runs repeatedly forever
void loop() {

    // Update the system continuously
    // This checks keypad input, handles password logic,
    // and manages the lock timing
    smartLock.update();
}