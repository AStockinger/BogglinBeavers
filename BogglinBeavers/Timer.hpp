/*******************************************************************************
 ** Project:      Bogglin' Beavers
 ** Date:         9 Sept 2018
 ** Description:  Specification file for Boggle class
 *******************************************************************************/

#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer{
    private:
        int timeLimit;
        std::clock_t start;

    public:
        Timer();
        Timer(int timeLimit);
        double getTime();
        void remainingTime();
        bool checkTime();


};
#endif