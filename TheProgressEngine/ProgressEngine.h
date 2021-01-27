#ifndef PROGRESSENGINE_H
#define PROGRESSENGINE_H

#include "Window.h"

class ProgressEngine
{

public:
	ProgressEngine();
	~ProgressEngine();
	bool OnCreate(std::string name_, int width_, int height_);
	void Run();
	bool GetIsRunning();
private:
	void Update(const float deltaTime_);
	void Render();
	void OnDestroy();
	Window* window;
	bool isRunning;

};
#endif // !PROGRESSENGINE_H
