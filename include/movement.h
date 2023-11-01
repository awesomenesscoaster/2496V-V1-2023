#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "PID.h"
#include "main.h"
#include "robot.h"


void left(float power);

void right(float power);

void move(float power);

void straightEncoder(int encoderValue, float power);

void spin(float power);

void moveTo(float power, float target);

void turnTo(float power, float target);

void moveTest(float target, float timeOut, float power_cap = 127);

void relTurn(float target, float timeOut, float power_cap = 127);
#endif