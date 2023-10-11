#include "main.h"
#include "robot.h"
#include "movement.h"

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

void move(float power){
    left(power);
    right(power);
}

void moveTo(float power, float target) {
    lf.tare_position();
    float kP = 0;
    float kI = 0;
    float kD = 0;
    float prevError = 0;
    int x = 0;
    float error = 0;
    while(true) {
        prevError = error;
        error = target - lf.get_position();
        float integral = integral + error;
        if (error < 1) {
            integral = 0;              
        } 
        else if (error > 300) {
            integral = 0;
        } 
        float derivative = prevError - error;
        move(kP*error+kI*integral+kD*derivative);
        if(error < 1){
            x++;
        }
        else if (x > 5){
            break;
        }
    }
}
