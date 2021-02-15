#ifndef PROGRESSENGINE_H
#define PROGRESSENGINE_H

#include <memory>
#include "Window.h"
#include "Timer.h"
#include "DebugLog.h"
#include "GameBase.h"
#include "Scene.h"

class ProgressEngine
{

public:

	//Prevents people from making move or copy constructors of the class

	ProgressEngine(const ProgressEngine&) = delete;
	ProgressEngine(ProgressEngine&&) = delete;
	ProgressEngine& operator=(const ProgressEngine&) = delete;
	ProgressEngine& operator=(const ProgressEngine&&) = delete;

	//Grabs the instance of our engine, in this case "instancedEngine"
	static ProgressEngine* GetInstance();

	//Checks that the engine's window is created
	bool OnCreate(std::string name_, int width_, int height_);

	//Uses the update function while isRunning = true, and calls OnDestroy once isRunning = false
	void Run();

	void Exit();

	//Takes the isRunning boolean and returns it for the run function
	bool GetIsRunning() const;

	int GetCurrentScene() const;

	void SetGameBase(GameBase* gameBase_);

	void SetCurrentScene(int sceneNum_);

private:
	ProgressEngine();
	~ProgressEngine();
	void Update(const float deltaTime_);
	void Render();
	void OnDestroy();

	//Holds a pointer specific to the ProgressEngine class
	static std::unique_ptr<ProgressEngine> instancedEngine;
	//Deletes our unique pointer
	friend std::default_delete<ProgressEngine>;

	//Pointer for our window, created when the program runs
	Window* window;

	//Checks to make sure if our engine is running
	bool isRunning;

	Timer* timer;
	unsigned int fps;

	GameBase* gameBase;

	int currentSceneNum;

};
#endif // !PROGRESSENGINE_H
