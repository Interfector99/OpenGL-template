#include "Window.hpp"

int main()
{
	Window window(600, 600, 60, false);
	window.initialize();
	window.run();
	window.destroy();
	return 0;
}