#include "main.h"
#include "pros/misc.h"
#include "robot.h"
#include "movement.cpp"
#include "controls.cpp"
#include <valarray>
#include <cmath>
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINE

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}


void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Initialized");
	imu.reset();
	pros::lcd::register_btn1_cb(on_center_button);

}


void disabled() {}

 
void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	while (true) {
		driver(1);
		pros::delay(20);

		//what is lil bro cooking 
		/*
		float fPwr, tPwr;

		int chasGraph = 0;

		if (controller.get_digital(DIGITAL_B)){
			chasGraph += 1;
		}


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
