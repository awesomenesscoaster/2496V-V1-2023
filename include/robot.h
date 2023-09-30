#include "main.h"
#include "pros/adi.hpp"

#ifndef ROBOT_H_
#define ROBOT_H_

extern pros::Controller controller;

extern pros::Motor cata;

extern pros::Motor lf;
extern pros::Motor lb;
extern pros::Motor lb;
extern pros::Motor rf;
extern pros::Motor rm;
extern pros::Motor rb;

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