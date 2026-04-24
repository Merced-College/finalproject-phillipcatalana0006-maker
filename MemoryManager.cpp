#include "MemoryManager.h"

// Load password from EEPROM
String MemoryManager::loadPassword() {

    String password = "";

    int length = EEPROM.read(0);

    if (length <= 0 || length > 20) {
        return "";
    }

    for (int i = 0; i < length; i++) {

        password += char(EEPROM.read(i + 1));
    }

    return password;
}

// Save password into EEPROM
void MemoryManager::savePassword(const String& password) {

    int length = password.length();

    EEPROM.write(0, length);

    for (int i = 0; i < length; i++) {

        EEPROM.write(i + 1, password[i]);
    }
}