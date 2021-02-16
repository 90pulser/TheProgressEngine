#include "ProgressEngine.h"

std::unique_ptr<ProgressEngine> ProgressEngine::instancedEngine = nullptr;

ProgressEngine::ProgressEngine() : window(nullptr), isRunning(false), fps(60), 
timer(nullptr), gameBase(nullptr), currentSceneNum(0)
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
	DebugLog::OnCreate();
	window = new Window();
	if (!window->OnCreate(name_, width_, height_)) 
	{
		DebugLog::FatalError("Window failed to initialize", "ProgressEngine.cpp", __LINE__);
		OnDestroy();
		return isRunning = false;
	}

	if (gameBase) {
		if (!gameBase->OnCreate()) {
			DebugLog::FatalError("Game failed to initialize", "ProgressEngine.cpp", __LINE__);
			OnDestroy();
			return isRunning = false;
		}
	}
	DebugLog::Info("Everything worked", "ProgressEngine.cpp", __LINE__);
	timer = new Timer;
	timer->Start();
	return isRunning = true;
}

void ProgressEngine::Run()
{
	while (isRunning) {
		timer->UpdateFrameTicks();
		Update(timer->GetDeltaTime());
		Render();		
		SDL_Delay(timer->GetSleepTime(fps));
	}
	//if (!isRunning) {
		OnDestroy();
	//}

}

void ProgressEngine::Exit()
{
	isRunning = false;
}

bool ProgressEngine::GetIsRunning() const
{
	return isRunning;
}

int ProgressEngine::GetCurrentScene() const
{
	return currentSceneNum;
}

void ProgressEngine::SetGameBase(GameBase* gameBase_)
{
	gameBase = gameBase_;
}

void ProgressEngine::SetCurrentScene(int sceneNum_)
{
	currentSceneNum = sceneNum_;
}

void ProgressEngine::Update(const float deltaTime_){
	if (gameBase) {
		gameBase->Update(deltaTime_);
		std::cout << deltaTime_ << std::endl;
	}
}

void ProgressEngine::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (gameBase) {
		gameBase->Render();
	}
	//CALL GAME RENDER
	SDL_GL_SwapWindow(window->GetWindow());
}

void ProgressEngine::OnDestroy()
{
	delete gameBase;
	gameBase = nullptr;

	delete window;
	window = nullptr;
	SDL_Quit();
	exit(0);
}
