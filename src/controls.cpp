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

<<<<<<< HEAD
	if(controller.get_digital_new_press(DIGITAL_R1)) {
		catapult::fire();
	}
	if (controller.get_digital_new_press(DIGITAL_R2)) {
		catapult::half();
=======
	// if(controller.get_digital_new_press(DIGITAL_X)){
	// 	cata.move(127);
	// }

	// if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
	// 	cata.move(0);
	// }

	// if (cataDown == false && cataHalf == false && cataTarget == false) { //When cata is not half, not moving to half, and not loaded, cata loads
	// 	cata.move(-127);	
	// }
	if (cataSwitch.get_value() == 1) { //When cata is loaded, options are: shoot or set half cata
		cataDown = true; 
		cata.move(0);
		if (controller.get_digital_new_press(DIGITAL_R1)){ //When pressed, all three states are false, and catapult fires and reloads
			cata.move(-127);
			if (cataSwitch.get_value() == 0) {
				cataDown = false;
			}
		}
		if (controller.get_digital_new_press(DIGITAL_R2)){ //When pressed, cataTarget is true temporarily until cata is at half pos and cataHalf = true
			cataDown = false;
			cataTarget = true; //cataTarget keeps cata from going to loading state where cata is not down nor half
			cata.tare_position();
			cata.move_absolute(300, 100); //Shoots, moves to half position
			cataHalf = true;
			cataTarget = false; //cataTarget is set to false again
		}
		if (cataHalf == true) { //When cata is in half position, pressing the same button moves cata to loading level
			cata.move(0); 
			if (controller.get_digital_new_press(DIGITAL_R2)) { //When pressed, all three states are false, and catapult fires and reloads
				cataHalf = false;
			}
		}
>>>>>>> ed2e9d1bdf85cb154ba9be3e604c7f0b7fec6b7a
	}
	catapult::run();

<<<<<<< HEAD
	if (controller.get_digital(DIGITAL_L1)) {
		intake.move(127);	
	}	
	else if (controller.get_digital(DIGITAL_L2)) {
		intake.move(-127);
	}
	else {
		intake.move(0);
	}
	
=======
	// Intake
	if (controller.get_digital(DIGITAL_L1)) {
		intake.move(127);
	}
	else if (controller.get_digital(DIGITAL_L2)) {
		intake.move(-127);
	}
	else{
		intake.move(0);
	}

	//Wings
>>>>>>> ed2e9d1bdf85cb154ba9be3e604c7f0b7fec6b7a
	if(controller.get_digital_new_press(DIGITAL_DOWN)){
		wings.set_value(!wingState);
		wingState = !wingState;
	}
}
