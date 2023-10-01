#include "robot.h"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor cata(20, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);

//intake side is the "front"
pros::Motor lf(1, MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lm(2, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lb(2, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(3, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rm(3, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rb(4, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor intake(10, MOTOR_GEARSET_6, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor_Group leftdrive({lf, lm, lb});
pros::Motor_Group rightdrive({rf, rm, rb});

pros::ADIDigitalIn cataSwitch(1);


//wing piston testing
pros::ADIDigitalOut leftWing(1, HIGH);
pros::ADIDigitalOut rightWing(2, HIGH);
