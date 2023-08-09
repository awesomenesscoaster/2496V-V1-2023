#include "robot.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Motor leftCata(20, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);
pros::Motor rightCata(15, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);

