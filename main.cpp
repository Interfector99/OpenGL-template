#include "Window.hpp"

int main()
{
	Window window(1280, 720, 60, false);
	window.initialize();
	window.run();
	window.destroy();
	return 0;
}