#include "main.h"
#include "robot.h"
#include "movement.h"

void left(float power) {
    leftFront.move(power);
    leftMid.move(power);
    leftBack.move(power);
}

void right(float power) {
    rightFront.move(power);
    rightMid.move(power);
    rightBack.move(power);
}

void move(float left_power, float right_power){
    left(left_power);
    right(right_power);
}

int sgn(double input){
    return input/std::abs(input);
}