#include "SmartLockSystem.h"

SmartLockSystem smartLock;
String inputBuffer = "";

void setup() {
    Serial.begin(9600);
    smartLock.begin();

    Serial.println("=== Arduino Smart Lock System ===");
    Serial.println("Commands:");
    Serial.println("Type password and press Enter to unlock");
    Serial.println("Type CHANGE to change password");
    Serial.println("Type LOCK to lock manually");
    Serial.println();
    Serial.println("Enter command or password:");
}

void loop() {
    while (Serial.available() > 0) {
        char c = Serial.read();

        if (c == '\r') {
            continue;
        }

        if (c == '\n') {
            inputBuffer.trim();

            if (inputBuffer.length() > 0) {
                smartLock.processInput(inputBuffer);
            }

            inputBuffer = "";
            Serial.println();
            Serial.println("Enter command or password:");
        } else {
            inputBuffer += c;
        }
    }

    smartLock.update();
}