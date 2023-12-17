#include <Arduino.h>
#include <drivingLogic.h>
#include <buttonLogic.h>

int motorSpeed = 50;
int delayTime = 5000;

void setup() {
    setupMotorPins();
    setupButtonPin();
    waitForStartButton();
}

// Loop function for driving driveForward, driveBackward, turnLeft, turnRight and stop
void loop() {
    driveForward(motorSpeed);
    delay(delayTime);
    driveBackward(motorSpeed);
    delay(delayTime);
    turnLeft(motorSpeed);
    delay(delayTime);
    turnRight(motorSpeed);
    delay(delayTime);
    stop();
    delay(delayTime);
}