#pragma once
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Texture.hpp"
#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

#include "stb/stb_image.h"

using namespace std;

class Entity
{
private:
	Shader shader;
	VAO vao;
	VBO vbo;
	EBO ebo;
	Texture texture;

	// shader variables
	GLuint scale;
public:
	Entity();
	void initialize(string vert, string frag, string path);
	void render(float s);
	void destroy();
};

