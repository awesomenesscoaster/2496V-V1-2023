#include "util.h"
#include "main.h"

class Timer {
    private:
        int t;
    public:
        Timer(){reset();}   
        void reset() {t = pros::millis();}
        int time() {return (pros::millis() - t);}
};
