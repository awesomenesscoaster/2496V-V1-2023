#ifndef __UTIL__
#define __UTIL__


#include "main.h"

class Timer {
    private:
        int t;
    public:
        Timer(){reset();}   
        void reset() {t = pros::millis();}
        int time() {return (pros::millis() - t);}
};

#endif