#include "main.h"
#include "robot.h"

void chas_move(float left_power, float right_power){
    topLeft.move(left_power);
    botLeft.move(left_power);
    topRight.move(right_power);
    botRight.move(right_power);
}

int sgn(double input){
    return input/std::abs(input);
}