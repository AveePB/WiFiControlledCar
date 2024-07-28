#ifndef CAR_MOVEMENT.H
#include <Arduino.h>

// GPIO Ports
#define ENA 16
#define ENB 42
#define IN1 15
#define IN2 14
#define IN3 35
#define IN4 38

// Speeds
#define SPEED 50
#define TURN_SPEED 80

class Motors {
    // Functions
    void init();
    void turnLeft();
    void turnRight();
    void moveForward();
    void moveBackward();    
};

#endif