#include "main.h"
#include "pros/misc.h"
#include "robot.h"
#include "cata.h"
#include "movement.h"
#include "controls.h"
#include <valarray>
#include <cmath>
#include <fstream>
#include <iostream>

void rightSideQual(){
    // absTurn(90, 1000);
    // absTurn(0, 1000);
    // absTurn(180, 1000);

    intake.move(127);
    moveTest(1500, 1000);
    intake.move(0);
    moveTest(-1300,750);
    absTurn(-55, 750);
    moveTest(-2000, 750);
    absTurn(-60, 750);
    moveTest(-1000, 750);
    moveTest(700, 1000);
    
    absTurn(180, 1000);
    
    intake.move(-127);
    moveTest(800, 1000);
    moveTest(-700, 750);
    absTurn(45, 750);
    intake.move(0);
    moveTest(-1200, 1000);
    absTurn(45, 750);
    moveTest(-2000, 1000);

}

void rightSideElims(){
    intake.move(127);
    moveTest(1500, 1000);
    intake.move(0);
    moveTest(-1300,750);
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

void oldrightSideQual(){
    wings.set_value(true);
    intake.move(-127);
    pros::delay(400);
    intake.move(0);
    moveTest(-1250,1000);
    pros::delay(200);
    wings.set_value(false);
    pros::delay(200);
    relTurn(-37,1500);
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

void leftSideQual(){
   intake.move(127);
   wings.set_value(true);
   intake.move(0);
   pros::delay(200);
   absTurn(-63, 750);
   moveTest(-1200, 750);
   absTurn(75, 750); 
}

void leftSideElims(){
    
}

void skills(){
    //Shooting Position
    right(127);
    pros::delay(200);
    right(0);
    pros::delay(1000);
    right(-127);
    pros::delay(200);
    right(0);
    pros::delay(200);

    moveTest(-5000, 1500);



}
