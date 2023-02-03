#include "Window.hpp"

int main()
{
	Window window(800, 800, 60, false);
	window.initialize();
	window.run();
	window.destroy();
	return 0;
}