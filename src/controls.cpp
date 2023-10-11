#include "main.h"
#include "robot.h"
#include "movement.h"
#include "autons.h"

bool cataDown = false;
void driver(int mode){
    bool half = false;
    bool wings = HIGH;
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    if (mode == 1){ //Tank
		left(controller.get_analog(ANALOG_LEFT_Y));
		right(controller.get_analog(ANALOG_RIGHT_Y));
    }
    if (mode == 0) { //Arcade
        move(controller.get_analog(ANALOG_LEFT_Y), controller.get_analog(ANALOG_LEFT_Y));
        move(-controller.get_analog(ANALOG_RIGHT_X), controller.get_analog(ANALOG_RIGHT_X));
    }

	// if (cataSwitch.get_value() !=0) {
	// 	cata.move(-127);				}
	// else if (controller.get_digital_new_press(DIGITAL_R1)){
	// 	cata.move(-127);
	// }
	// if (controller.get_digital_new_press(DIGITAL_DOWN)){ //Half cata on
	// 	half = true;
	// 	cata.tare_position();
	// 	cata.move_absolute(100, 100);
	// }
	// while (half != false){ //Half cata off
	// 	if (controller.get_digital_new_press(DIGITAL_Y)){
	// 		half = false; 
	// 	}
	// }
	if (!cataDown){
		cata.move(-127);
		cataDown = cataSwitch.get_value();
	}
	else{
		cata.move(0);
		if (controller.get_digital_new_press(DIGITAL_R1)){
			cata.move(-127);
		}
		if (controller.get_digital_new_press(DIGITAL_DOWN)){
			half = true;
			cata.tare_position();
			cata.move_absolute(300, 100);
		}
		while (half != false){
			cata.move(0);
			if (controller.get_digital_new_press(DIGITAL_Y)){
				half = false;
			}
		}
		cataDown = cataSwitch.get_value();
	}

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
	if(controller.get_digital_new_press(DIGITAL_DOWN)){
		leftWing.set_value(!wings);
		rightWing.set_value(!wings);
		wings = !wings;
	}

	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){ //PID test
		chasPID(300);
	}
}
