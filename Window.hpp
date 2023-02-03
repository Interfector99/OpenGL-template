#pragma once
#include"Entity.hpp"

class Window
{
private:
    unsigned int WIDTH;
    unsigned int HEIGHT;
    unsigned int FRAMERATE;
    bool IS_FULLSCREEN;

    GLFWwindow* window;

    Entity background;
public:
    Window(int WIDTH, int HEIGHT, int FRAMERATE, bool IS_FULLSCREEN);
    void initialize();
    void run();
    void destroy();
};