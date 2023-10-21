#include "robot.h"
#include "util.cpp"
#include "cata.h"

namespace catapult {
    Timer t1 = Timer();
    cataStates state = idle;
    pros::Mutex smtx;
    void run() {
        while(true) {
            smtx.lock();
            switch (state)
                {
                case firing:
                    cata.move(-127);
                    if (!cataSwitch.get_value()) {
                        state = reloading;
                    }
                    break;
                case reloading:
                    cata.move(-127);
                    if (cataSwitch.get_value()) {
                        cata.move(0);
                        state = idle;
                    }
                    break;
                case halfState:
                    if(t1.time() < 700) {
                        cata.move(-127);
                    }
                    else {
                        state = idle;
                        cata.move(0);
                    }
                    break;
                case matchloading:
                    cata.move(-100);
                    break;
                case idle:
                    break;
            }
            smtx.unlock();
            pros::delay(20);
        }
    }

    void fire() {
        smtx.lock();
        state = firing;
        smtx.unlock();
    }
    void half() {
        smtx.lock();
        state = halfState;
        t1.reset();
        smtx.unlock();
    }

    void matchload() {
        smtx.lock();
        state = matchloading;
        smtx.unlock();
    }

}