#include "robot.h"
#include "util.h"

#ifndef __CATA__
#define __CATA__

namespace catapult {
    enum cataStates {
        firing,
        halfState,
        idle,
        reloading,
        matchloading,
        move
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
    }

    void fire() {
        state = firing;
    }
    void half() {
        state = halfState;
        t1.reset();
    }

    void matchload() {
        state = matchloading;
    }

}

#endif