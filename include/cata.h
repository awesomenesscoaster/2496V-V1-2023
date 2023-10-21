#include "robot.h"
#include "util.h"

#ifndef __CATA__
#define __CATA__

namespace catapult{
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
    void run();
    void fire();
    void half();
    void matchload();
};


#endif