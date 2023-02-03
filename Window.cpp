#include "Window.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

Window::Window(int WIDTH, int HEIGHT, int FRAMERATE, bool IS_FULLSCREEN)
{
	// set parameters
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->FRAMERATE = FRAMERATE;
	this->IS_FULLSCREEN = IS_FULLSCREEN;
}

void Window::initialize()
{
	// set display properties
	glfwInit();
	window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Template", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		// TODO exception
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// set icon
	GLFWimage images[1];
	images[0].pixels = stbi_load("Textures/icon.png", &images[0].width, &images[0].height, 0, 4);
	glfwSetWindowIcon(window, 1, images);
	stbi_image_free(images[0].pixels);

	// set additional parameters
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glBlendFunc(GL_ONE, GL_ONE);
}

void Window::run()
{
	// make background entity
	background.initialize();

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);

		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// triangle entity draw
		background.render();

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Delete all the objects we've created
	background.destroy();
}

void Window::destroy()
{
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	cout << "Program ended successfully" << endl;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}