#include "AlarmSystem.h"

AlarmSystem::AlarmSystem(int buzzer, int redLED, int greenLED) {
    buzzerPin = buzzer;
    redLEDPin = redLED;
    greenLEDPin = greenLED;
}

void AlarmSystem::begin() {
    pinMode(buzzerPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);
    pinMode(greenLEDPin, OUTPUT);

    digitalWrite(buzzerPin, LOW);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
}

void AlarmSystem::beepShort() {
    tone(buzzerPin, 1000, 200);
    delay(250);
}

void AlarmSystem::beepSuccess() {
    tone(buzzerPin, 1500, 150);
    delay(180);
    tone(buzzerPin, 1800, 150);
    delay(180);
}

void AlarmSystem::triggerAlarm() {
    for (int i = 0; i < 5; i++) {
        digitalWrite(redLEDPin, HIGH);
        tone(buzzerPin, 2000);
        delay(300);

        digitalWrite(redLEDPin, LOW);
        noTone(buzzerPin);
        delay(200);
    }

    showLocked();
}

void AlarmSystem::showLocked() {
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
}

void AlarmSystem::showUnlocked() {
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
}