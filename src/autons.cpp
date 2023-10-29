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
    wings.set_value(true);
    intake.move(-127);
    pros::delay(200);
    intake.move(0);
    moveTest(-1250,1000);
    pros::delay(200);
    wings.set_value(false);
    pros::delay(200);
    absTurn(-37,1500);
    moveTest(-1200, 1000);
    pros::delay(200);
    moveTest(1500, 1000);
    pros::delay(200);
    absTurn(20, 1000);
    pros::delay(200);
    moveTest(200, 800);
    pros::delay(200);
    moveTest(2000, 1000);
} 

void leftSideQual(){
    moveTest(-2500, 1000);
    pros::delay(200);
    moveTest(400, 1000);
    pros::delay(200);
    absTurn(175, 1000);
    wings.set_value(true);
    pros::delay(200);
    moveTest(-1000, 1000);
    wings.set_value(false);
    pros::delay(200);
    moveTest(-200, 500);
    pros::delay(400);
    absTurn(-45, 1000);
    // pros::delay(400);
    // moveTest(-2000, 1000);
    

}

void rightSideElims(){

}

void leftSideElims(){
    
}

void skills(){
    right(127);
    // cata.move(-127);
    // pros::delay(40000);
    pros::delay(230);
    right(0);
    pros::delay(1000);
    right(-127);
    pros::delay(300);
    right(0);
    pros::delay(300);
    moveTest(-950, 1000);
    pros::delay(200);
    absTurn(-5, 1000);
    pros::delay(200);
    moveTest(-4000, 2000);
    pros::delay(200);
    absTurn(-90, 1000);
    pros::delay(200);
    moveTest(-1200, 1000);
    pros::delay(200);
    absTurn(-90, 1000);
    pros::delay(200);
    moveTest(-2000, 1000);
    pros::delay(200);
    absTurn(90, 1000);
    moveTest(-4000, 2000);




}
