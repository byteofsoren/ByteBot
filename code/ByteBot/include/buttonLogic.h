#include <Arduino.h>
#define BUT_PIN 2

// Function for setting up the button pin
void setupButtonPin() {
    pinMode(BUT_PIN, INPUT);
}

// Function for reading the button pin
bool readButtonPin() {
    return digitalRead(BUT_PIN);
}

// Function for wait start button to be pressed
void waitForStartButton() {
    while (readButtonPin() == false) {
        delay(100);
    }
}