#include "StartScene.h"

StartScene::StartScene() : Scene()
{

}

StartScene::~StartScene()
{
}

bool StartScene::OnCreate()
{
	DebugLog::Info("start scene", "StartScene.cpp", __LINE__);
	ProgressEngine::GetInstance()->SetCurrentScene(1);
	return true;
}

void StartScene::Update(const float deltaTime_)
{
}

void StartScene::Render()
{
}
