#include "Timer.hpp"

#include <iostream>
using namespace std;

Timer::Timer(){
    started = true;
    resetted = true;
    start = 0;
    end = 0;
}

void Timer::startClock(){
	if(!isStarted()) {
		if(resetted)
			start = (unsigned long) clock();
		else
			start -= end - (unsigned long) clock();
		started = true;
		resetted = false;
	}
}
        
bool Timer::isStarted(){
    return started;
}

void Timer::stopClock(){
    if(isStarted()){
		end = (unsigned long) clock();
		started = false;
	}
}

void Timer::reset() {
	bool running = isStarted();
	if(running)
		stopClock();
	resetted = true;
	start = 0;
	end = 0;
	if(running)
		startClock();
}

unsigned long Timer::getTime(){
	if(isStarted())
		return ((unsigned long) clock() - start) / CLOCKS_PER_SEC;
	else
		return end - start;
}