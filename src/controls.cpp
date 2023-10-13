#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "robot.h"
#include "cata.hpp"

bool half = false;
bool wingState = false;

void driver(){
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	left(controller.get_analog(ANALOG_LEFT_Y));
	right(controller.get_analog(ANALOG_RIGHT_Y));

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
