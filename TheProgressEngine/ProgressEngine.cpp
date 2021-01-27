#include "ProgressEngine.h"

ProgressEngine::ProgressEngine() : window(nullptr), isRunning(false)
{
	window = nullptr;
	isRunning = false;
}

ProgressEngine::~ProgressEngine()
{
	OnDestroy();
}

bool ProgressEngine::OnCreate(std::string name_, int width_, int height_)
{
	window = new Window();
	if (!window->OnCreate(name_, width_, height_)) {
		std::cout << "Window failed to initialize!" << std::endl;
		OnDestroy();
		return isRunning = false;
	}
	return isRunning = true;
}

void ProgressEngine::Run()
{
	while (isRunning) {
		Update(0.016f);
		Render();		
	}
	if (!isRunning) {
		OnDestroy();
	}

}

bool ProgressEngine::GetIsRunning()
{
	return false;
}

void ProgressEngine::Update(const float deltaTime_)
{
}

void ProgressEngine::Render()
{
}

void ProgressEngine::OnDestroy()
{
}
