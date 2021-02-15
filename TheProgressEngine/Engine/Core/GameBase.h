#ifndef GAMEBASE_H
#define GAMEBASE_H

class GameBase
{
public:
	GameBase() {}
	virtual ~GameBase() {}

	virtual bool OnCreate() = 0;
	virtual void Update(const float deltaTime_) = 0;
	virtual void Render() = 0;
};
#endif // !GAMEBASE_H
