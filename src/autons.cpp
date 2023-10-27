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
    moveTest(-1250);
    pros::delay(200);
    wings.set_value(false);
    pros::delay(200);
    absTurn(-35);
    moveTest(-1500);
} 

void leftSideQual(){

}

void rightSideElims(){

}

void leftSideElims(){
    
}

void skills(){

}
