#pragma once
#include"Entity.hpp"

using namespace std;

class Window
{
private:
    unsigned int WIDTH;
    unsigned int HEIGHT;
    unsigned int FRAMERATE;
    bool IS_FULLSCREEN;

    GLFWwindow* window;
public:
    Window(int WIDTH, int HEIGHT, int FRAMERATE, bool IS_FULLSCREEN);
    void run();
    void render();
    void destroy();
};