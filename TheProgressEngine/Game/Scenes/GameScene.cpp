#include "GameScene.h"

GameScene::GameScene() : shape(nullptr)
{

}

GameScene::~GameScene()
{
    model = nullptr;

    delete shape;
    shape = nullptr;
}

bool GameScene::OnCreate()
{
    DebugLog::Info("game scene", "GameScene.cpp", __LINE__);

    ProgressEngine::GetInstance()->SetCamera(new Camera());
    ProgressEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
    ProgressEngine::GetInstance()->GetCamera()->AddLightSource(new LightSource(glm::vec3(0.0f, 0.0f, 2.0f),
        0.1f, 0.5f, 0.5f,
        glm::vec3(1.0f, 1.0f, 1.0f)));

    model = new Model("Resources/Models/Dice.obj",
        "Resources/Materials/Dice.mtl",
        ShaderHandler::GetInstance()->GetShader("defaultShader"));
    //model->SetScale(glm::vec3(0.5f));
    shape = new GameObject(model);

    return true;
}

void GameScene::Update(const float deltaTime_)
{
    shape->Update(deltaTime_);
}

void GameScene::Render()
{
    shape->Render(ProgressEngine::GetInstance()->GetCamera());
}
