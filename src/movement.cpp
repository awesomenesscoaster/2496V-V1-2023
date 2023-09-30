#include "main.h"
#include "robot.h"

void left(float power) {
    lf.move(power);
    lm.move(power);
    lb.move(power);
}

void right(float power) {
    rf.move(power);
    rm.move(power);
    rb.move(power);
}

void move(float left_power, float right_power){
    left(left_power);
    right(right_power);
}

int sgn(double input){
    return input/std::abs(input);
}