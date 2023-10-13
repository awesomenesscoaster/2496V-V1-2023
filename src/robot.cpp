#include "robot.h"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor cata(7, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);

//intake side is the "front"
pros::Motor lf(1, MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lm(2, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lb(3, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(4, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rm(5, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rb(6, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor intake(9, MOTOR_GEARSET_6, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::ADIDigitalIn cataSwitch(3);

//wing piston testing
pros::ADIDigitalOut wings(1, false);

pros::Imu imu(8);
