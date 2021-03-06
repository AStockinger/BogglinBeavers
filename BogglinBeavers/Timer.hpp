#ifndef TIMER_H
#define TIMER_H

#include <time.h>

class Timer{
    private:
        unsigned long start;
        unsigned long end;
        bool started;
        bool resetted;
    public:
        Timer();
        bool isStarted();
        void startClock();
        void stopClock();
        void reset();
        unsigned long getTime();
};
#endif