#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"
#include "cata.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINE

bool half = false;
bool wingState = false;

void driver(){
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	lf.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	lm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	lb.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rf.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rb.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	float lPwr, rPwr;
	float lAxis, rAxis;

	rAxis = controller.get_analog(ANALOG_RIGHT_Y) ;
	lAxis = controller.get_analog(ANALOG_LEFT_Y);

	rPwr = (abs(rAxis) > 2) ? (sgn(rAxis)) * (-127 * cos((2*M_PI*rAxis)/508)+127) : 0;
	lPwr = (abs(lAxis) > 2) ? (sgn(lAxis)) * (-127 * cos((2*M_PI*lAxis)/508)+127) : 0;

	chas_move(lPwr, rPwr);

	if(controller.get_digital_new_press(DIGITAL_R1)) {
		catapult::fire();
	}
	if (controller.get_digital_new_press(DIGITAL_R2)) {
		catapult::half();
	}
	catapult::run();

	if (controller.get_digital(DIGITAL_L1)) {
		intake.move(127);	
	}	
	else if (controller.get_digital(DIGITAL_L2)) {
		intake.move(-127);
	}
	else {
		intake.move(0);
	}
	
	if(controller.get_digital_new_press(DIGITAL_DOWN)){
		wings.set_value(!wingState);
		wingState = !wingState;
	}
}
