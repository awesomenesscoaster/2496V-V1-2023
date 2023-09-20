#include "main.h"
#include "pros/misc.h"
#include "robot.h"
#include <valarray>
#include <cmath>
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINE

// #include "autons.h"


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
 
void competition_initialize() {}
// 	controller.clear();
// 	while(true){
		
// 	}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	leftCata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightCata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	catapult.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	bool wings = HIGH;

	while (true) {
		
		//Wings
		if(controller.get_digital_new_press(DIGITAL_DOWN)){
			leftWing.set_value(!wings);
			rightWing.set_value(!wings);
			wings = !wings;
		}

		//Catapult
		if (cataSwitch.get_value() != 0){
			catapult.move(-127);
		}
		else if (controller.get_digital_new_press(DIGITAL_R1)){
			catapult.move(-127);
		}

		// if (controller.get_digital(DIGITAL_R1)){
		// 	catapult.move(127);
		// }
		// else if (controller.get_digital(DIGITAL_R2)){
		// 	catapult.move(-127);
		// }
		// else{
		// 	catapult.move(0);
		// }

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

		float fPwr, tPwr;
		float lAxis, rAxis;

		//Assuming Arcade Mode -- Can always change
		lAxis = controller.get_analog(ANALOG_LEFT_Y);
		rAxis = controller.get_analog(ANALOG_RIGHT_X);
		
		int chasGraph = 0;

		if (controller.get_digital(DIGITAL_B)){
			chasGraph += 1;
		}
		
		/*
		//Default
		if (chasGraph == 0){
			controller.clear();
			controller.print(0,0,"Default Graph");

			fPwr = (std::abs(lAxis) > 2) ? lAxis : 0;
			tPwr = (std::abs(rAxis) > 2) ? rAxis : 0;
		}

		//Exponential
		else if (chasGraph == 1){
			controller.clear();
			controller.print(0,0,"Exponential Graph");

			fPwr = (std::abs(lAxis) > 2) ? (sgn(lAxis) * (1.2*pow(1.03566426, sgn(lAxis)*lAxis) - 1.2 + sgn(lAxis)*0.2*lAxis)) : 0;
			tPwr = (std::abs(rAxis) > 2) ? (sgn(rAxis) * (1.2*pow(1.03566426, sgn(rAxis)*rAxis) - 1.2 + sgn(rAxis)*0.2*rAxis)) : 0;
		}

		// Cosine
		else if (chasGraph == 2){
			controller.clear();
			controller.print(0,0,"Cosine Graph");

			fPwr = (std::abs(lAxis) > 2) ? (sgn(lAxis)) * (-127 * cos((2*M_PI*lAxis)/508) + 127) : 0;
			tPwr = (std::abs(rAxis) > 2) ? (sgn(rAxis)) * (-127 * cos((2*M_PI*rAxis)/508) + 127) : 0;
		}

		chas_move(fPwr-tPwr, fPwr+tPwr);
		*/
	}
	
}
