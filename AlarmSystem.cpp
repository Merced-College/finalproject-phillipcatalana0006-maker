#include "AlarmSystem.h"

// Constructor assigns pins
AlarmSystem::AlarmSystem(int buzzer, int redLED, int greenLED) {
    buzzerPin = buzzer;
    redLEDPin = redLED;
    greenLEDPin = greenLED;
}

// Initialize buzzer and LEDs
void AlarmSystem::begin() {

    pinMode(buzzerPin, OUTPUT);

    pinMode(redLEDPin, OUTPUT);

    pinMode(greenLEDPin, OUTPUT);

    digitalWrite(redLEDPin, LOW);

    digitalWrite(greenLEDPin, LOW);
}

// Short beep for keypad press
void AlarmSystem::beepKeypress() {
    tone(buzzerPin, 1200, 25);
}

// Short warning beep
void AlarmSystem::beepShort() {
    tone(buzzerPin, 1000, 150);
}

// Success sound
void AlarmSystem::beepSuccess() {

    tone(buzzerPin, 1500, 150);

    delay(200);

    tone(buzzerPin, 1800, 150);
}

// Alarm sound sequence
void AlarmSystem::triggerAlarm() {

    for (int i = 0; i < 5; i++) {

        digitalWrite(redLEDPin, HIGH);

        tone(buzzerPin, 2000);

        delay(250);

        digitalWrite(redLEDPin, LOW);

        noTone(buzzerPin);

        delay(250);
    }

    showLocked();
}

// Red LED when locked
void AlarmSystem::showLocked() {

    digitalWrite(redLEDPin, HIGH);

    digitalWrite(greenLEDPin, LOW);
}

// Green LED when unlocked
void AlarmSystem::showUnlocked() {

    digitalWrite(redLEDPin, LOW);

    digitalWrite(greenLEDPin, HIGH);
}