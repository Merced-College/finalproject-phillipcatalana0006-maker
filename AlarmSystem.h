#ifndef ALARMSYSTEM_H
#define ALARMSYSTEM_H

#include <Arduino.h>

class AlarmSystem {
private:
    int buzzerPin;
    int redLEDPin;
    int greenLEDPin;

public:
    AlarmSystem(int buzzer, int redLED, int greenLED);

    void begin();

    void beepShort();
    void beepSuccess();
    void triggerAlarm();

    void showLocked();
    void showUnlocked();
};

#endif