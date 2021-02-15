#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

//Converts milliseconds to seconds, avoids "Magic Numbers"
constexpr float MILLI_TO_SEC = 1000.0f;

class Timer{
public:
	/*The four lines of code below ensure that a timer can't be created anywhere else.
	The ampersands in this code are references to the Timer declaration*/

	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator=(const Timer&) = delete;
	Timer& operator=(Timer&&) = delete;

	//Our constructor and deconstructor for the Timer class

	Timer();
	~Timer();

	void Start();
	void UpdateFrameTicks();
	float GetDeltaTime() const;
	unsigned int GetSleepTime(const unsigned int fps_) const;
	float GetCurrentTickMilli() const;
	float GetCurrentTickSec() const;
private:
	unsigned int previousTicks;
	unsigned int currentTicks;
};

#endif // !TIMER_H
