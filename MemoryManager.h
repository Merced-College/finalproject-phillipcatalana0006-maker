#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <Arduino.h>
#include <EEPROM.h>

class MemoryManager {
public:
    String loadPassword();
    void savePassword(const String& password);
};

#endif