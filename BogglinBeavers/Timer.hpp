#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer{
    private:
        std::clock_t start;

    public:
        Timer();
        double getTime();
        void remainingTime();
        bool checkTime();


};
#endif