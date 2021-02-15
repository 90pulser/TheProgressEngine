#include "Timer.h"

Timer::Timer() : previousTicks(0), currentTicks(0){
}

Timer::~Timer()
{
}

void Timer::Start()
{
	previousTicks = currentTicks = SDL_GetTicks();
}

void Timer::UpdateFrameTicks()
{
	previousTicks = currentTicks;
	currentTicks = SDL_GetTicks();
}

float Timer::GetDeltaTime() const
{
	return (currentTicks - previousTicks) / MILLI_TO_SEC;
}

unsigned int Timer::GetSleepTime(const unsigned int fps_) const {
	unsigned int millisecondsPerFrame = MILLI_TO_SEC / fps_;
	if (millisecondsPerFrame == 0) {
		return 0;
	}
	unsigned int sleepTime = millisecondsPerFrame - (SDL_GetTicks() - currentTicks);
	if (sleepTime > millisecondsPerFrame) {
		return millisecondsPerFrame;
	}
	return sleepTime;
}

float Timer::GetCurrentTickMilli() const
{
	return static_cast<float>(currentTicks);
}

float Timer::GetCurrentTickSec() const
{
	return currentTicks / MILLI_TO_SEC;
}
