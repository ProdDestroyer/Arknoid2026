#pragma once
#include <chrono>
class TimeStamp {
public:
	TimeStamp();
	float getDelta();
private:
	std::chrono::steady_clock::time_point last;
};