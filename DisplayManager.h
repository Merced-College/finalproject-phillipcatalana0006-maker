#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <Arduino.h>
#include <LiquidCrystal.h>

// Class responsible for controlling the LCD 1602 display
class DisplayManager {

private:

    // LCD object using 4-bit mode
    // Pin layout:
    // RS = 12
    // E  = 11
    // D4 = 5
    // D5 = 4
    // D6 = 3
    // D7 = 2
    LiquidCrystal lcd;

public:

    // Constructor
    DisplayManager();

    // Initializes LCD screen
    void begin();

    // Displays two lines of text
    // line1 = top row
    // line2 = bottom row
    void showMessage(String line1, String line2);
};

#endif