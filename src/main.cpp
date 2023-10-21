#include "main.h"
#include "pros/misc.h"
#include "autons.h"
#include "robot.h"
#include "movement.h"
#include "controls.h"
#include "cata.h"
#include <valarray>
#include <cmath>
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINE

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Initialized");
	pros::Task cataTask(catapult::run);
	//imu.reset();
}
//hello
void disabled() {}

void competition_initialize() {}

void autonomous() {
	rightSide();
	// moveTest(2000);
}

void opcontrol() {
	controller.clear();
	while (true) {
		driver();
		pros::delay(20);
	}
	
}
