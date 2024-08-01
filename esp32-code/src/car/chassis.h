#pragma once
#ifndef CHASSIS_H 
#define CHASSIS_H

// GPIO pins
extern const int ENA;
extern const int IN1;
extern const int IN2;

extern const int ENB;
extern const int IN3;
extern const int IN4;

// Regular speed param
extern const int SPEED;

enum class Movement {
    Stop, Forward, Backward, Left, Right
};

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