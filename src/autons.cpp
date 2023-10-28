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
    moveTest(-870, 1000);
    pros::delay(200);
    moveTest(1400, 1000);
    pros::delay(200);
    absTurn(20, 1000);
    pros::delay(200);
    moveTest(200, 800);
    absTurn(-167, 1000);
    moveTest(-2400, 2000);
} 

void leftSideQual(){
    moveTest(-2500, 1000);
}

void rightSideElims(){

}

void leftSideElims(){
    
}

void skills(){

}
