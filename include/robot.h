#include "main.h"
#include "pros/adi.hpp"

#ifndef ROBOT_H_
#define ROBOT_H_

extern pros::Controller controller;

extern pros::Motor cata;

extern pros::Motor leftFront;
extern pros::Motor leftMid;
extern pros::Motor leftBack;
extern pros::Motor rightFront;
extern pros::Motor rightMid;
extern pros::Motor rightBack;

extern pros::ADIDigitalIn cataSwitch;

extern pros::Motor intake;

extern pros::Motor_Group leftdrive;
extern pros::Motor_Group rightdrive;

extern pros::ADIDigitalOut leftWing;
extern pros::ADIDigitalOut rightWing;

extern pros::Imu imu;

void chas_move(float left_power, float right_power);
int sgn(double input);

#endif