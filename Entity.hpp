#pragma once
#include<iostream>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"Texture.hpp"
#include"Shader.hpp"
#include"VAO.hpp"
#include"VBO.hpp"
#include"EBO.hpp"

#include"stb/stb_image.h"

class Entity
{
private:
public:
	Entity();
	void render();
	void destroy();
};

