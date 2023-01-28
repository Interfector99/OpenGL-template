#include "Window.hpp"
#include <thread>

void foo()
{
	Window window(800, 600, 60, false);
	window.run();
	window.destroy();
}

int main()
{
	thread first(foo);
	first.join();
	return 0;
}