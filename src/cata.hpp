#ifndef __CATA__
#define __CATA__

#include "robot.h"
#include "util.cpp"

namespace catapult {
    enum cataStates {
        firing,
        halfState,
        idle,
        reloading
    };
    cataStates state;
    Timer t1;
    void run() {
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
                if(t1.time() < 650) {
                    cata.move(-127);
                }
                else {
                    state = idle;
                    cata.move(0);
                }
            case idle:
                break;
        }
    }

    void fire() {
        state = firing;
    }
    void half() {
        state = halfState;
        t1.reset();
    }
}

#endif