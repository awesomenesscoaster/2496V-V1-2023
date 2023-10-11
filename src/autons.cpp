#include "main.h"
#include "pros/misc.h"
#include "robot.h"
#include "movement.h"
#include "controls.h"
#include <valarray>
#include <cmath>
#include <fstream>
#include <iostream>

double kP;
double kI;
double maximum;

void chasPID(double target){
    double error;
    double voltage;
    double integral;
    double current;
    int counter;

    while(current < target){
        current = lf.get_encoder_units();
        error = target - current;
        integral += error*(current/target);
        if (error == 10 || error > maximum){
            integral = 0;
        }
        
        voltage = error*kP + integral*kI;
        pros::delay(15);
        counter++;

        if (counter%10 == 0){
            controller.print(0, 2, "Error: %f", error);
            controller.print(1, 2, "Current: %f", current);
        }

        left(voltage);
        right(voltage);

    }
}
