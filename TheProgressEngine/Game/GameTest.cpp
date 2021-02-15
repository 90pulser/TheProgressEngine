#include "GameTest.h"

GameTest::GameTest() : GameBase(), currentSceneNum(0), currentScene(nullptr)
{
}

GameTest::~GameTest()
{
    delete currentScene;
    currentScene = nullptr;
}

bool GameTest::OnCreate()
{
    if (ProgressEngine::GetInstance()->GetCurrentScene() == 0) {
        currentScene = new StartScene();
        currentSceneNum = 0;
        return currentScene->OnCreate();
    }
    std::cout << "Engine's scene is not initialized to 0" << std::endl;
    return false;
}

void GameTest::Update(const float deltaTime_)
{
    if (currentSceneNum != ProgressEngine::GetInstance()->GetCurrentScene()) {
        BuildScene();
    }
    currentScene->Update(deltaTime_);
}

void GameTest::Render()
{
    currentScene->Render();
}

void GameTest::BuildScene()
{
    delete currentScene;
    currentScene = nullptr;

    switch (ProgressEngine::GetInstance()->GetCurrentScene()) {
    case 1:
        currentScene = new GameScene();
        break;
    default: //case 0:
        currentScene = new StartScene();
        break;
    }

    currentSceneNum = ProgressEngine::GetInstance()->GetCurrentScene();
    if (!currentScene->OnCreate()) {
        std::cout << "Scene failed to be created" << std::endl;
        ProgressEngine::GetInstance()->Exit();
    }
}
