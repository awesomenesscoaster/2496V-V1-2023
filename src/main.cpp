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

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Initialized");
	imu.reset();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (true) {
		driver();
		pros::delay(20);
	}
	
}
