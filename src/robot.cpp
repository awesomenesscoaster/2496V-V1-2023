#include "robot.h"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor cata(7, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);

//intake side is the "front"
pros::Motor leftFront(1, MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftMid(2, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor leftBack(3, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rightFront(4, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rightMid(5, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rightBack(6, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor intake(10, MOTOR_GEARSET_6, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor_Group leftdrive({leftFront, leftMid, leftBack});
pros::Motor_Group rightdrive({rightFront, rightMid, rightBack});

pros::ADIDigitalIn cataSwitch(3);

//wing piston testing
pros::ADIDigitalOut leftWing(1, HIGH);
pros::ADIDigitalOut rightWing(2, HIGH);
