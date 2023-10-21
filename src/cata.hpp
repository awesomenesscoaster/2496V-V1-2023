//#include "robot.h"

#ifndef __CATA__
#define __CATA__

<<<<<<< HEAD:include/cata.hpp
namespace catapult{
=======
#include "robot.h"
#include "util.cpp"

namespace catapult {
>>>>>>> 3d6c2f24b30414ba56bde2603cf260d687c15362:src/cata.hpp
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