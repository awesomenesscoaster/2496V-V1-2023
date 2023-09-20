#include "main.h"
#include "pros/adi.hpp"

#ifndef ROBOT_H_
#define ROBOT_H_

extern pros::Controller controller;

extern pros::Motor leftCata;
extern pros::Motor rightCata;

extern pros::Motor topLeft;
extern pros::Motor botLeft;

extern pros::Motor topRight;
extern pros::Motor botRight;

extern pros::ADIDigitalIn cataSwitch;

extern pros::Motor intake;

extern pros::Motor_Group catapult;
extern pros::Motor_Group leftChassis;
extern pros::Motor_Group rightChassis;

extern pros::ADIDigitalOut leftWing;
extern pros::ADIDigitalOut rightWing;

extern pros::Imu imu;

void chas_move(float left_power, float right_power);
int sgn(double input);

#endif