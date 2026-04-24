#include "KeypadInput.h"

// Initializes keypad (nothing needed here)
void KeypadInput::begin() {
}

// Reads keypad button press
char KeypadInput::getKey() {

    return keypad.getKey();
}