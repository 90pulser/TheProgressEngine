#include "ProgressEngine.h"

std::unique_ptr<ProgressEngine> ProgressEngine::instancedEngine = nullptr;

ProgressEngine::ProgressEngine() : window(nullptr), isRunning(false)
{

}

ProgressEngine::~ProgressEngine()
{
}

ProgressEngine* ProgressEngine::GetInstance()
{
	if (instancedEngine.get() == nullptr)
	{
		instancedEngine.reset(new ProgressEngine);
	}
	return instancedEngine.get();
}

bool ProgressEngine::OnCreate(std::string name_, int width_, int height_)
{
	window = new Window();
	if (!window->OnCreate(name_, width_, height_)) 
	{
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
	return isRunning;
}

void ProgressEngine::Update(const float deltaTime_)
{
}

void ProgressEngine::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//CALL GAME RENDER
	SDL_GL_SwapWindow(window->GetWindow());
}

void ProgressEngine::OnDestroy()
{
	delete window;
	window = nullptr;
	SDL_Quit();
	exit(0);
}
