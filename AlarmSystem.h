#ifndef ALARMSYSTEM_H
#define ALARMSYSTEM_H

#include <Arduino.h>

// Class responsible for buzzer and LED alerts
class AlarmSystem {

private:

    int buzzerPin;
    int redLEDPin;
    int greenLEDPin;

public:

    AlarmSystem(int buzzer, int redLED, int greenLED);

    void begin();

    void beepKeypress();
    void beepShort();
    void beepSuccess();

    void triggerAlarm();

    void showLocked();
    void showUnlocked();
};

#endif