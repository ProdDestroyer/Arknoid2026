#pragma once
#include <chrono>
class TimeStamp {
public:
	TimeStamp();
	float GetDelta();
private:
	std::chrono::steady_clock::time_point last;
};