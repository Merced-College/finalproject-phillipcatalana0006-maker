[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=23605883)
# cpp_finalProjects

Upload your code and report here to this repo for your final project, change this README file to explain your final project github repo files.

# Arduino Smart Lock System

## Project Description

The Arduino Smart Lock System is a security-based embedded C++ project that simulates a smart door lock using an Arduino board. The system allows users to enter a password using a keypad. If the correct password is entered, a servo motor rotates to unlock the door. If incorrect passwords are entered multiple times, a buzzer alarm activates for security purposes.

The system also uses EEPROM memory to save the password even after power is turned off, and an LCD 1602 display to provide real-time feedback to the user such as password prompts, access granted, access denied, and lock status.

This project demonstrates object-oriented programming in C++, hardware integration, embedded systems design, and real-world security applications.

---

## Features

- Password entry using keypad
- Servo motor door unlock system
- Buzzer alarm after multiple failed attempts
- EEPROM password storage
- LCD display feedback system
- Keypress sound feedback
- Lock and unlock status monitoring
- Password remains saved after power loss

---

## How to Compile and Run

### Required Components

- Arduino Uno
- 4x4 Keypad
- Servo Motor
- Buzzer
- LCD 1602 Display
- Potentiometer
- Jumper Wires
- Breadboard

### Required Libraries

Install these libraries in Arduino IDE:

- Keypad.h
- Servo.h
- EEPROM.h
- LiquidCrystal.h

### Steps

1. Open Arduino IDE
2. Connect Arduino board to computer
3. Open the SmartLock project folder
4. Verify all `.h` and `.cpp` files are included
5. Install required libraries
6. Upload code to Arduino
7. Open Serial Monitor if needed
8. Use keypad to enter password
9. Observe LCD messages and servo response

---

## Data Structures Used

### Arrays

Used for storing the entered password and saved password.

### Strings

Used for LCD display messages and system prompts.

### EEPROM Storage

Used to permanently store password data after power is turned off.

---

## Algorithms Used

### Password Verification Algorithm

Compares entered password with stored password.

### Failed Attempt Tracking

Counts incorrect entries and activates buzzer after limit is reached.

### Servo Unlock Logic

Controls servo motor rotation based on correct authentication.

---

## Contributors

Group Project

Created by: John Catalana and Cristian Galindo

---

## Future Improvements

- RFID card access
- Fingerprint scanner integration
- Mobile app unlock system
- Bluetooth connectivity
- Time-based access logs