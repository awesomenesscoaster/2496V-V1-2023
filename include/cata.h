#pragma once

#include "util.h"

namespace catapult{
    enum cataStates {
        firing,
        halfState,
        idle,
        reloading,
        matchloading,
        move
    };
    extern cataStates state;
    extern Timer t1;
    extern pros::Mutex smtx;

    extern void run();
    extern void fire();
    extern void half();
    extern void matchload();
};