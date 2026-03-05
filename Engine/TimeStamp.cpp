#include "TimeStamp.h"

TimeStamp::TimeStamp()
{
	last = std::chrono::steady_clock::now();
}

float TimeStamp::GetDelta()
{
	const std::chrono::steady_clock::time_point old = last;
	const std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
	const std::chrono::duration<float> duration = current - old;
	last = current;
	return duration.count();
}

