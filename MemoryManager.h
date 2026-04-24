#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <Arduino.h>
#include <EEPROM.h>

// Class responsible for saving and loading password
class MemoryManager {

public:

    // Reads stored password from EEPROM memory
    String loadPassword();

    // Writes password into EEPROM memory
    void savePassword(const String& password);
};

#endif