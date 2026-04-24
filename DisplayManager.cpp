#include "DisplayManager.h"

// Constructor initializes LCD pin layout
DisplayManager::DisplayManager() : lcd(12, 11, 5, 4, 3, 2) {
}

// Start LCD and clear screen
void DisplayManager::begin() {

    lcd.begin(16, 2);

    lcd.clear();
}

// Displays two lines of text
void DisplayManager::showMessage(String line1, String line2) {

    lcd.clear();

    lcd.setCursor(0, 0);

    lcd.print(line1);

    lcd.setCursor(0, 1);

    lcd.print(line2);
}