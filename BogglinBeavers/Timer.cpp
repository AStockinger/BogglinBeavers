#include "Timer.hpp"

#include <iostream>
using namespace std;

Timer::Timer(){
	start = clock();
	timeLimit = 180;
}

Timer::Timer(int timeLimit){
	this->timeLimit = timeLimit;
	start = clock();
}

double Timer::getTime(){
	return (clock() - start) / (double) CLOCKS_PER_SEC;
}

void Timer::remainingTime(){
	cout << timeLimit - static_cast<int>(Timer::getTime()) << " seconds remain..." << endl;
}

bool Timer::checkTime(){
	if (Timer::getTime() < timeLimit){
		return true;
	} 
	else{
		return false;
	}
}