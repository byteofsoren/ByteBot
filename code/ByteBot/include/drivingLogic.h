#include <Arduino.h>
#define MAX_SPEED 255

#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5

void setupMotorPins() {
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

// Function for analogWrite to ENA and ENB with duty cycle as parameter
void setSpeed(int dutyCycle) {
  // Map linearly from 0-100 to 0-255
  dutyCycle = map(dutyCycle, 0, 100, 0, MAX_SPEED);

  // Set speed of ENA and ENB
  analogWrite(ENA, dutyCycle);
  analogWrite(ENB, dutyCycle);
}


// Function for driving driveForward with duty cycle as parameter
void driveForward(int dutyCycle) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  setSpeed(dutyCycle);
}

// Function for driving driveBackward with duty cycle as parameter
void driveBackward(int dutyCycle) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  setSpeed(dutyCycle);
}

// Function for turning turnLeft with duty cycle as parameter
void turnLeft(int dutyCycle) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  setSpeed(dutyCycle);
}

// Function for turning turnRight with duty cycle as parameter
void turnRight(int dutyCycle) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  setSpeed(dutyCycle);
}

// Function for stopping
void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
