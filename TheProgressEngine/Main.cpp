#include "Engine\Core\ProgressEngine.h"
#include "Game\GameTest.h"

int main(int argc, char* argv[]) {
	ProgressEngine::GetInstance()->SetGameBase(new GameTest);

	if (!ProgressEngine::GetInstance()->OnCreate("Progress Engine", 800, 600))
	{
		DebugLog::FatalError("Engine failed to initialize!", "Main.cpp", __LINE__);
		return 0;
	}
	
	ProgressEngine::GetInstance()->Run();
	return 0;
}
