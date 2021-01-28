#include "ProgressEngine.h"

ProgressEngine* engine;

int main(int argc, char* argv[]) {
	engine = new ProgressEngine();
	if (!engine->OnCreate("Progress Engine", 800, 600))
	{
		delete engine;
		engine = nullptr;
		return 0;
	}
	engine->Run();
	delete engine;
	engine = nullptr;
	return 0;
}
