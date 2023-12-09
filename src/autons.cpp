#include "cata.h"
#include "controls.h"
#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "robot.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <valarray>

void rightSideQual2(){
  intake.move(127);
  pros::delay(400);
  skillsMove(1800, 1100);
  intake.move(0);
  skillsMove(-1300, 750);
  absTurn(-55, 750);
  skillsMove(-2000, 750);
  absTurn(-115, 750);
  skillsMove(-1000, 750);
  skillsMove(700, 1000);
  absTurn(-90, 1000);
  intake.move(-127);
  skillsMove(800, 1000);
  skillsMove(-700, 750);
  absTurn(135, 750);
  intake.move(0);
  skillsMove(-1500, 1000);
  absTurn(0, 750);
  skillsMove(-2000, 750);


}

void rightSideQual() {
  intake.move(127);
  pros::delay(400);
  moveTest(1800, 1100);
  intake.move(0);
  moveTest(-1300, 750);
  absTurn(-55, 750);
  moveTest(-2000, 750);
  absTurn(-60, 750);
  moveTest(-1000, 750);
  moveTest(600, 1000);

  absTurn(180, 1000);

  intake.move(-127);
  moveTest(800, 1000);
  moveTest(-700, 750);
  absTurn(45, 750);
  intake.move(0);
  moveTest(-1500, 1000);
  absTurn(45, 750);
  blocker.set_value(true);
  moveTest(-1800, 1000);
}

void rightSideElims() {
  intake.move(127);
  moveTest(1500, 1000);
  intake.move(0);
  moveTest(-1300, 750);
  absTurn(-55, 750);
  moveTest(-2000, 750);
  absTurn(-60, 750);
  moveTest(-1200, 750);
  moveTest(600, 750);
  

  absTurn(180, 750);

  intake.move(-127);
  moveTest(1000, 1000);
  moveTest(-700, 750);
  intake.move(0);

  absTurn(-75, 750);
  intake.move(127);
  moveTest(3000, 2000);

  absTurn(120, 750);
  intake.move(-127);
  moveTest(500, 750);
  absTurn(-100, 750);
  intake.move(127);
  moveTest(1000, 750);
  absTurn(145, 750);
  intake.move(-127);
  moveTest(2000, 750);
}

void oldrightSideQual() {
  wings.set_value(true);
  intake.move(-127);
  pros::delay(400);
  intake.move(0);
  moveTest(-1250, 1000);
  pros::delay(200);
  wings.set_value(false);
  pros::delay(200);
  relTurn(-37, 1500);
  moveTest(-1200, 1000);
  pros::delay(200);
  moveTest(750, 1000);
  pros::delay(200);
  relTurn(20, 1000);
  pros::delay(200);
  moveTest(200, 800);
  pros::delay(200);
  moveTest(2000, 1000);
}

void leftSideQual() {
  intake.move(127);
  wings.set_value(true);
  pros::delay(200);
  absTurn(-80, 750);
  intake.move(0);
  absTurn(-37, 750);
  wings.set_value(false);
  moveTest(-2400, 1000);
  moveTest(500, 750);
  absTurn(90, 750);
  blocker.set_value(true);
  moveTest(-2500, 750);
  absTurn(60, 750);
  moveTest(-750, 750);

  //    intake.move(127);
  //    moveTest(-2400, 1000);
  //    moveTest(700, 1000);
  //    intake.move(0);
  //    absTurn(150, 750);
  //    wings.set_value(true);
  //    pros::delay(200);
  //    moveTest(-800, 750);
  //    absTurn(-45, 750);
}

void leftSideElims() {
  intake.move(127);
  moveTest(-2000, 750);
  pros::delay(100);
  intake.move(0);
  wings.set_value(true);
  absTurn(90, 750);
  moveTest(-2000, 750);
  pros::delay(200);
  wings.set_value(false);
  intake.move(-127);
  moveTest(1700, 750);
  intake.move(0);
  moveTest(-200, 750);
  // pros::delay(500);
  // moveTest(-1000,750);
  // intake.move(0);
  // absTurn(45, 750);
  // moveTest(-1750, 850);
  // wings.set_value(true);
  // absTurn(-50, 750);
  // moveTest(-800, 750);
  // moveTest(400, 750);
  // absTurn(90, 750);
  // intake.move(-127);
  // moveTest(1200, 750);
}

void skills() {
  // Shooting Position
  right(127);
  pros::delay(200);
  right(0);
  pros::delay(1000);

  cata.move(-110);
  pros::delay(34400);
  cata.move(0);

  pros::delay(1000);

  absTurn(45, 1000);

  skillsMove(-1200, 900);
  absTurn(0, 1000);

  skillsMove(-4450, 2000);
  intake.move(127);

  absTurn(-90, 1000);
  skillsMove(-1400, 700);
  absTurn(-180, 1000);
  skillsMove(-1400, 700);

  absTurn(-90, 1000);
  skillsMove(-2100, 1000);
  absTurn(0, 1000);
  wings.set_value(true);

  skillsMove(-2400, 850);
  skillsMove(1750, 750);
  wings.set_value(false);
  absTurn(90, 1000);
  skillsMove(-800, 700);
  absTurn(0, 1000);
  wings.set_value(true);
  skillsMove(-2000, 750);

  skillsMove(1500, 500);
  absTurn(60, 1000);
  wings.set_value(true);
  skillsMove(-1000, 700);
  wings.set_value(false);
  skillsMove(-1000, 700);

}
