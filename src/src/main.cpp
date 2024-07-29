#include <Arduino.h>
#include "CarChassis.h"

// Components
Motors motors;

// Setup function
void setup() {
    motors.initialize();
}

// Loop function
void loop() {
    motors.moveForward();
    delay(3000);
    
    motors.stop();
    delay(3000);

    motors.moveBackward();
    delay(3000);

    motors.stop();
    delay(3000);
}