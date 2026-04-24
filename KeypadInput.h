#ifndef KEYPADINPUT_H
#define KEYPADINPUT_H

#include <Arduino.h>
#include <Keypad.h>

// Class responsible for reading keypad button presses
class KeypadInput {

private:

    // Number of rows and columns on the keypad
    static const byte ROWS = 4;
    static const byte COLS = 4;

    // Layout of the keypad buttons
    // This matches the physical 4x4 keypad
    char keys[ROWS][COLS] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };

    // Arduino pins connected to keypad rows
    byte rowPins[ROWS] = {
        6, 7, 8, A1
    };

    // Arduino pins connected to keypad columns
    byte colPins[COLS] = {
        A2, A3, A4, A5
    };

    // Create keypad object using layout and pin mapping
    Keypad keypad = Keypad(
        makeKeymap(keys),
        rowPins,
        colPins,
        ROWS,
        COLS
    );

public:

    // Initializes keypad system
    void begin();

    // Reads and returns the pressed key
    // Returns 0 if no key is pressed
    char getKey();
};

#endif