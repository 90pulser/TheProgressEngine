#include "Engine\Core\ProgressEngine.h"

int main(int argc, char* argv[]) {
	if (!ProgressEngine::GetInstance()->OnCreate("Progress Engine", 800, 600))
	{
		std::cout << "Engine failed to initialize!" << std::endl;
		return 0;
	}
	
	ProgressEngine::GetInstance()->Run();
	return 0;
}
