#ifndef GAMETEST_H
#define GAMETEST_H

#include "..\Engine\Core\ProgressEngine.h"
#include "Scenes\StartScene.h"
#include "Scenes\GameScene.h"

class GameTest : public GameBase
{
public:
	GameTest();
	virtual ~GameTest();

	bool OnCreate() override;
	void Update(const float deltaTime_) override;
	void Render() override;
private:
	int currentSceneNum;
	Scene* currentScene;
	void BuildScene();
};
#endif // !GAMETEST_H
