#include "Timer.hpp"

#include <iostream>
using namespace std;

Timer::Timer(){
	start = clock();
}

double Timer::getTime(){
	return (clock() - start) / (double) CLOCKS_PER_SEC;
}

void Timer::remainingTime(){
	cout << 180 - static_cast<int>(Timer::getTime()) << " seconds remain..." << endl;
}

bool Timer::checkTime(){
	if (Timer::getTime() < 180){
		return true;
	} 
	else{
		return false;
	}
}
