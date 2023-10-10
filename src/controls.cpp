#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "robot.h"

void halfCata () {
  controller.clear();
    while(cata.get_position() > -850){
      cata.move(-80);
    }
  cata.move(0);
}

void fullCata () {
  while(cata.get_position() > -1100){
    cata.move(-127);
  }
}

void driver(int mode) {
  bool half = false;
  bool wings = HIGH;
  cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  if (mode == 1) { // Tank
    left(controller.get_analog(ANALOG_LEFT_Y));
    right(controller.get_analog(ANALOG_RIGHT_Y));
  }
  if (mode == 0) { // Arcade
    move(controller.get_analog(ANALOG_LEFT_Y),
         controller.get_analog(ANALOG_LEFT_Y));
    move(-controller.get_analog(ANALOG_RIGHT_X),
         controller.get_analog(ANALOG_RIGHT_X));
  }

  if (controller.get_digital_new_press(DIGITAL_R2)){
    halfCata();
    controller.print(0,0,"%f ", cata.get_position());
  }

  int cataPosition = 0;

  cata.tare_position();
  if (controller.get_digital_new_press(DIGITAL_R2)) {
    cataPosition += 1;
  }

  if (cataPosition == 0) {
    halfCata();
  }

  if (cataSwitch.get_value() == 0 && cataPosition == 1) {
    cata.move(-127);
  }

  if (cataPosition == 2) {
    cata.move(-127);
    cataPosition = 0;
  }

  // if (cataSwitch.get_value() !=0) {
  // 	cata.move(127);				}
  // else if (controller.get_digital_new_press(DIGITAL_R1)){
  // 	cata.move(127);
  // }
  // if (controller.get_digital_new_press(DIGITAL_DOWN)){ //Half cata on
  // 	half = true;
  // 	cata.tare_position();
  // 	cata.move_absolute(100, 100);
  // while (half != false){ //Half cata off
  // 	if (controller.get_digital_new_press(DIGITAL_Y)){
  // 		half = false;
  // 	}
  // }

  // Intake
  if (controller.get_digital(DIGITAL_L1)) {
    intake.move(127);
  } else if (controller.get_digital(DIGITAL_L2)) {
    intake.move(-127);
  } else {
    intake.move(0);
  }

  // Wings
  if (controller.get_digital_new_press(DIGITAL_DOWN)) {
    leftWing.set_value(!wings);
    rightWing.set_value(!wings);
    wings = !wings;
  }
}
