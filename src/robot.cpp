#include "robot.h"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor leftCata(20, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);
pros::Motor rightCata(15, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);

pros::Motor topLeft(1, MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor botLeft(2, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor topRight(3, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor botRight(4, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor intake(10, MOTOR_GEARSET_6, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor_Group catapult ({leftCata, rightCata});
pros::Motor_Group leftChassis ( {topLeft, botLeft} );
pros::Motor_Group rightChasasis ( {topRight, botRight} );

pros::ADIDigitalIn cataSwitch(1);

//wing piston testing
pros::ADIDigitalOut leftWing(1, HIGH);
pros::ADIDigitalOut rightWing(2, HIGH);
