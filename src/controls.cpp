#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"
#include "cata.cpp"
#include <cmath>
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINE

bool half = false;
bool wingState = false;

void driver(){
	// Chassis Temperature
	float leftMotorTemp, rightMotorTemp;
	leftMotorTemp = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature())/3;
	rightMotorTemp = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature())/3;

	int printTimer = 0;
	if(!(printTimer % 5)){
		controller.print(0,0,"%f", leftMotorTemp);
		controller.print(2,0,"%f", rightMotorTemp);
	}
	printTimer += 1;

	// Initialize Brake Modes
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	lf.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	lm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	lb.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rf.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rb.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	// Tank Graph
	float lPwr, rPwr;
	float lAxis, rAxis;

	lAxis = controller.get_analog(ANALOG_LEFT_Y) ;
	rAxis = controller.get_analog(ANALOG_RIGHT_Y);

	rPwr = rAxis;
	lPwr = lAxis;

	//rPwr = (abs(rAxis) > 2) ? (sgn(rAxis)) * (-127 * cos((2*3.14159*rAxis)/508)+127) : 0;
	//lPwr = (abs(lAxis) > 2) ? (sgn(lAxis)) * (-127 * cos((2*3.14159*lAxis)/508)+127) : 0;

	chas_move(lPwr, rPwr);
	// Cata Control
	if(controller.get_digital_new_press(DIGITAL_R1)) {
		catapult::fire();
	}
	if (controller.get_digital_new_press(DIGITAL_R2)) {
		catapult::half();
	}
	if(controller.get_digital_new_press(DIGITAL_B)) {
		catapult::matchload();
	}
	catapult::run();

	//Intake Control
	if (controller.get_digital(DIGITAL_L2)) {
		intake.move(127);	
	}	
	else if (controller.get_digital(DIGITAL_L1)) {
		intake.move(-127);
	}
	else {
		intake.move(0);
	}
	
	//Wings Control
	if(controller.get_digital_new_press(DIGITAL_DOWN)){
		wings.set_value(!wingState);
		wingState = !wingState;
	}
}
