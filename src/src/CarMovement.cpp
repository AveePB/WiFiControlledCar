#include <Arduino.h>
#include "CarMovement.h"

// Function declarations
void Motors::init() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void Motors::turnLeft() {}

void Motors::turnRight() {}

void Motors::moveForward() {}

void Motors::moveBackward() {}