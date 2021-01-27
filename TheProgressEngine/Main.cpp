#include "Window.h"

Window* window;

int main(int argc, char* argv[]) {
	Window* window = new Window();
	if (!window->OnCreate("Progress Engine", 800, 600))
	{
		delete window;
		window = nullptr;
		return 0;
	}
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SwapWindow(window->GetWindow());
	SDL_Delay(5000);
	delete window;
	window = nullptr;
	return 0;
}