#include "main.h"
#include "robot.h"
#include "movement.h"
#include "PID.h"

int sgn(double input){
    return input/std::abs(input);
}

void resetEncoders(){
    lf.tare_position();
    lm.tare_position();
    lb.tare_position();
    rf.tare_position();
    rm.tare_position();
    rb.tare_position();
}

void chas_move(float left_power, float right_power){
    lf.move(left_power);
    lm.move(left_power);
    lb.move(left_power);
    rf.move(right_power);
    rm.move(right_power);
    rb.move(right_power);
}

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

void move1(float power){
    left(power);
    right(power);
}

void spin(float power){
    left(power);
    right(-power);
}

void timedMove(int speed, int time){
    chas_move(speed, speed);
    pros::delay(time);
    chas_move(0,0);
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
        move1(kP*error+kI*integral+kD*derivative);
        if(error < 1){
            x++;
        }
        else if (x > 5){
            break;
        }
    }
}

void move(float target, bool toggle_slew, float slew_rate, float power_cap){
    float encoder_average;
    float voltage;
    float currPos = 0;
    int printTimer = 0;
    float imuPos;
    int count = 0;
    
    PID straight(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

    resetEncoders();
    controller.clear();
    straight.resetVars();
    imuPos = imu.get_rotation();

    while(true){
        encoder_average = (lb.get_position()+rb.get_position())/2;

        currPos = target - encoder_average;
        if(!(printTimer % 5)){
            controller.print(0,0,"%f",currPos);
        }
        printTimer += 1;

        voltage = straight.calc(target, encoder_average, STRAIGHT_INTEGRAL_KICK, STRAIGHT_MAX_INTEGRAL, slew_rate , toggle_slew);

        if(std::abs(voltage) > power_cap){
            voltage = power_cap*voltage/std::abs(voltage);
        }

        chas_move(voltage, voltage);

        if(std::abs(target-encoder_average <= 4)){
            count++;
        }
        if(count >= 10){
            break;
        }
        pros::delay(10);
    }
    chas_move(0,0);

}

void absTurn(float target, bool toggle_slew, float slew_rate, float power_cap){
    float voltage;
    float currPos = 0;
    float heading;
    int printTimer = 0;
    int count = 0;
    
    PID absRotate(TURN_KP, TURN_KI, TURN_KD);

    controller.clear();
    absRotate.resetVars();

    while(true){
        currPos = fmod(imu.get_rotation() - heading, 360);
        voltage = absRotate.calc(target, currPos, TURN_INTEGRAL_KICK, TURN_MAX_INTEGRAL, slew_rate, toggle_slew);

        chas_move(voltage, -voltage);

        if(!(printTimer % 5)){
            controller.print(0,0,"%f", currPos);
        }
        printTimer += 1;

        if(std::abs(target-currPos) <= 50){
            count++;
        }
        if(count >= 10){
            break;
        }
        pros::delay(10);
    }
    chas_move(0,0);
}



