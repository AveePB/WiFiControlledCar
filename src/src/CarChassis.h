#ifndef CARCHASSIS_H 
#include <Arduino.h>

// GPIO pins
const int ENA = 19;
const int IN1 = 21;
const int IN2 = 3;

const int ENB = 23;
const int IN3 = 1;
const int IN4 = 22;

class Motors {
    public:
        void initialize();
        void stop();
        void moveForward();
        void moveBackward();
        void turnLeft();
        void turnRight();
};

#endif