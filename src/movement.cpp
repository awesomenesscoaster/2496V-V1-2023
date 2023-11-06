#include "PID.h"
#include "main.h"
#include "robot.h"
#include "util.cpp"


int sgn(double input) { return input / std::abs(input); }

void resetEncoders() {
  lf.tare_position();
  lm.tare_position();
  lb.tare_position();
  rf.tare_position();
  rm.tare_position();
  rb.tare_position();
}

void chas_move(float left_power, float right_power) {
  lf.move(left_power);
  lm.move(left_power);
  lb.move(left_power);
  rf.move(right_power);
  rm.move(right_power);
  rb.move(right_power);
}

void left(float power) {
  lf.move(power);
  lm.move(power);
  lb.move(power);
}

void right(float power) {
  rf.move(power);
  rm.move(power);
  rb.move(power);
}

void move1(float power) {
  left(power);
  right(power);
}

void straightEncoder(int encoderValue, float power) {
  rf.move_relative(encoderValue, power);
  rm.move_relative(encoderValue, power);
  rb.move_relative(encoderValue, power);
  lf.move_relative(encoderValue, power);
  lm.move_relative(encoderValue, power);
  lb.move_relative(encoderValue, power);
}

void spin(float power) {
  left(power);
  right(-power);
}

void timedMove(int speed, int time) {
  chas_move(speed, speed);
  pros::delay(time);
  chas_move(0, 0);
}

// void moveTo(float target, int timeOut) {
//   resetEncoders();
//   float derivative;
//   float integral;
//   float position;
//   float speed;
//   float kP = 1.9;
//   float kI = 0.035;
//   float kD = 10;
//   float kJ = 6.5;
//   float prevError = 0;
//   int x = 0;
//   float error = 0;
//   imu.tare_heading();
//   float initial = imu.get_heading();
//   float heading;
//   float headingError;

//   Timer t1;

//   while (true) {
//     heading = imu.get_heading();
//     headingError = heading - initial;
//     if (heading - initial > 180) {
//       headingError = heading - initial - 360;
//     }
//     else {
//       headingError = heading - initial;
//     }
//     position = (lf.get_position()+rf.get_position())/2;
//     prevError = error;
//     error = target - position;
//     integral = integral + error;
    
//     if (fabs(error) < 1) {
//       integral = 0;
//     } else if (integral > 50) {
//       integral = 50;
//     }
    
//     derivative = error - prevError;
//     speed = kP*error + kI*integral + kD*derivative;
    
//     chas_move(speed - kJ*headingError, speed + kJ*headingError);
//     if (error < 1) {
//       x++;
//     } 
//     else if (x > 30) {
//       break;
//     }

//     if (t1.time() > timeOut){
//       break;
//     }

//     pros::delay(10);
//   }
// }

void moveTest(float target, float timeOut, float power_cap) {
  float encoder_average;
  float voltage;
  float currPos = 0;
  int printTimer = 0;
  float imuInit;
  float heading;
  int count = 0;

  PID straight(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

  resetEncoders();
  controller.clear();
  straight.resetVars();
  imuInit = imu.tare_rotation();

  Timer t1;
  while (true) {
    encoder_average = (lb.get_position() + rb.get_position()) / 2;

    heading = imuInit - imu.get_rotation();
    heading = heading;

    currPos = target - encoder_average;
    if (!(printTimer % 5)) {
      controller.print(0, 0, "%f", currPos);
    }
    printTimer += 1;

    voltage = straight.calc(target, encoder_average, STRAIGHT_INTEGRAL_KICK, STRAIGHT_MAX_INTEGRAL);

    if (std::abs(voltage) > power_cap) {
      voltage = power_cap * voltage / std::abs(voltage);
    }

    chas_move(voltage + heading, voltage - heading);

    if(t1.time() > timeOut){
      break;
    }

    if (std::abs(target - encoder_average) <= 0.8) {
      count++;
    }
    if (count >= 10) {
      break;
    }
    pros::delay(10);
  }
  chas_move(0, 0);
}

void absTurn(float target,  float timeOut){
  float voltage;
  float turnKi;
  float turnKD;
  float turnKP;
  float heading;
  int printTimer = 0;
  int count = 0;
}

void relTurn(float target, float timeOut, float power_cap) {
  float voltage;
  float turnKI;
  float turnKD;
  float turnKP;
  float currPos = 0;
  float heading;
  int printTimer = 0;
  int count = 0;

  if (std::abs(target) <= 30) {
    turnKP = 1.87;
    turnKI = 0.027;
    turnKD = 1.5;
  } else if (std::abs(target) <= 45) {
    turnKP = 1.8;   // 1.1
    turnKI = 0.073; // 0.015
    turnKD = 1.42;  // 1.3
  } else if (std::abs(target) <= 90) {
    turnKP = 1.2;   //// 1.05
    turnKI = 0.005; // 0.035
    turnKD = 1.6;   // 1.35
  } else if (std::abs(target) <= 135) {
    turnKP = 1.1;
    turnKI = 0.005;
    turnKD = 1.9;
  } else if (std::abs(target) <= 180) {
    turnKP = 1;
    turnKI = 0.015;
    turnKD = 1.95;
  }

  PID absRotate(turnKP, turnKI, turnKD);

  controller.clear();
  absRotate.resetVars();
  imu.tare_rotation();

  Timer t1;
  while (true) {
    // currPos = fmod(imu.get_heading() - heading, 360);

    if (target > 175) {
      if (imu.get_heading() > 300) {
        currPos = imu.get_heading() - 360;
      } else {
        currPos = imu.get_heading();
      }
    } else if (target < -175) {
      if (imu.get_heading() > 60) {
        currPos = imu.get_heading() - 360;
      } else {
        currPos = imu.get_heading();
      }
    } else {
      if (imu.get_heading() > 180) {
        currPos = imu.get_heading() - 360;
      } else {
        currPos = imu.get_heading();
      }
    }

    voltage = absRotate.calc(target, currPos, TURN_INTEGRAL_KICK, TURN_MAX_INTEGRAL);

    chas_move(voltage, -voltage);

    if (!(printTimer % 5)) {
      controller.print(0, 0, "%f", currPos);
    }
    printTimer += 1;

    if (std::abs(target - currPos) <= 2) {
      count++;
    }
    if (count >= 10) {
      break;
    }

    if (t1.time() > timeOut){
      break;
    }

    pros::delay(10);
  }
  chas_move(0, 0);
}

float heading_init;
void absTurn(float abstarget, int timeOut){

    Timer t1;
    float voltage;
    float position;
    float turnKP;
    float turnKI;
    float turnKD;
    int count = 0;
 
    int printTimer = 0;
    float printPos = 0;
    controller.clear();

    if (std::abs(abstarget) <= 30) {
      turnKP = 1.87;
      turnKI = 0.027;
      turnKD = 1.5;
    } else if (std::abs(abstarget-imu.get_rotation()) <= 45) {
      turnKP = 1.8;   // 1.1
      turnKI = 0.065; // 0.015
      turnKD = 1.42;  // 1.3
    } else if (std::abs(abstarget-imu.get_rotation()) <= 90) {
      turnKP = 1.2;   //// 1.05
      turnKI = 0.005; // 0.035
      turnKD = 1.6;   // 1.35
    } else if (std::abs(abstarget) <= 135) {
      turnKP = 1.1;
      turnKI = 0.005;
      turnKD = 1.9;
    } else if (std::abs(abstarget-imu.get_rotation()) <= 180) {
      turnKP = 1;
      turnKI = 0.02;
      turnKD = 1.95;
    }
    
    PID absRotate(turnKP, turnKI, turnKD);
    absRotate.resetVars();

    while(true){

        position = fmod(imu.get_rotation() - heading_init, 360); 
        voltage = absRotate.calc(abstarget, position, TURN_INTEGRAL_KICK, TURN_MAX_INTEGRAL);
        chas_move(voltage, -voltage);

        if (!(printTimer % 5)) {
            controller.print(0,0, "%f", position);
        }
        printTimer += 1;
        if (std::abs(abstarget - position) <= 0.75){
          count++;
        }

        if (count >= 10){
        break;
        }

        if (t1.time() > timeOut){
        break;
        }

        pros::delay(10);
    }
    chas_move(0,0);
    printf("count: %d\r\n", (count));
}
