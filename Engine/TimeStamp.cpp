#include "TimeStamp.h"

TimeStamp::TimeStamp()
{
	last = std::chrono::steady_clock::now();
}

float TimeStamp::getDelta()
{
	const auto old = this->last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> dt = last - old;

	return dt.count();
}
