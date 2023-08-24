#include "robot.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor leftCata(20, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);
pros::Motor rightCata(15, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);

pros::Motor topLeft(1, MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor botLeft(2, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor topRight(3, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor botRight(4, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

