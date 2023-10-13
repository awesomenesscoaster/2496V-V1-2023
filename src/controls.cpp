#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "robot.h"
#include "cata.hpp"

bool half = false;
bool wingState = false;
bool cataDown = false;
bool cataHalf = false;
bool cataTarget = false;

void driver(){
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	left(controller.get_analog(ANALOG_LEFT_Y));
	right(controller.get_analog(ANALOG_RIGHT_Y));

	std::cout << cataSwitch.get_value() << std::endl;

	// if (cataDown == false && cataHalf == false && cataTarget == false) {
	// 	 //When cata is not half, not moving to half, and not loaded, cata load 
	// 	if (cataSwitch.get_value() == 1) {
	// 		cataDown = true;
	// 		if (cataDown == true) {
	// 			cata.move(0);
	// 		}

	// 		if (controller.get_digital_new_press(DIGITAL_R1)) { //When pressed, all three states are false, and catapult fires and reloads
	// 			cata.move(-127);
	// 		}
	// 		/*if (controller.get_digital_new_press(DIGITAL_R2)) { //When pressed, cataTarget is true temporarily until cata is at half pos and cataHalf = true
	// 			cata.move_absolute(500, 100); //Shoots, moves to half position
	// 			cata.move(0);
	// 			cataHalf = true;
	// 			if (controller.get_digital_new_press(DIGITAL_R2)) {
	// 				cataHalf = false;
	// 			} 
	// 		}*/
	// 	}
	// 	else {
	// 		cata.move(-127);
	// 	}	
	// }
	/*else { //When cata is loaded, options are: shoot or set half cata
		if (controller.get_digital_new_press(DIGITAL_R1)) { //When pressed, all three states are false, and catapult fires and reloads
			cata.move(-127);
		}
		if (cataSwitch.get_value() == 0) {
			cataDown = false;
			cataTarget = false;
		}
		if (controller.get_digital_new_press(DIGITAL_R2)) { //When pressed, cataTarget is true temporarily until cata is at half pos and cataHalf = true
			cata.tare_position();
			cata.move_absolute(300, 100); //Shoots, moves to half position
			cataHalf = true;
		}
		if (cataHalf == true) { //When cata is in half position, pressing the same button moves cata to loading level
			cata.move(0); 
			if (controller.get_digital_new_press(DIGITAL_R2)) cataHalf = false; //When pressed, all three states are false, and catapult fires and reloads
		} 
		
	}*/

	if(controller.get_digital_new_press(DIGITAL_R1)) {
		catapult::fire();
	}
	if (controller.get_digital_new_press(DIGITAL_R2)) {
		catapult::half();
	}
	catapult::run();

	// Intake
	if (controller.get_digital(DIGITAL_L1)) {
		intake.move(127);	
	}	
	if (controller.get_digital(DIGITAL_L2)) {
		intake.move(-127);
	}
	else {
		intake.move(0);
	}
	
	//Wings
	if(controller.get_digital_new_press(DIGITAL_DOWN)){
		wings.set_value(!wingState);
		wingState = !wingState;
	}
}
