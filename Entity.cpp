#include "Entity.hpp"

// Vertices coordinates
GLfloat quadVertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	0.0f, 0.0f, // Lower left corner
	-0.5f,  0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	0.0f, 1.0f, // Upper left corner
	 0.5f,  0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
	 0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
};

// Indices for vertices order
GLuint quadIndices[] =
{
	0, 2, 1, // Upper triangle
	0, 3, 2 // Lower triangle
};

Entity::Entity()
{

}

void Entity::initialize()
{
	shader = Shader("Shaders/background.vert", "Shaders/background.frag");
	vao.initialize();
	vao.Bind();
	vbo = VBO(quadVertices, sizeof(quadVertices));
	ebo = EBO(quadIndices, sizeof(quadIndices));
	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();
	scale = glGetUniformLocation(shader.ID, "scale");
	string path = "Textures/valley.jpg";
	texture = Texture(path.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	texture.texUnit(shader, "tex0", 0);
}

void Entity::render()
{
	// check
	shader.Activate();
	glUniform1f(scale, 1.0f);
	texture.Bind();
	vao.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Entity::destroy()
{
	vao.Delete();
	vbo.Delete();
	ebo.Delete();
	texture.Delete();
	shader.Delete();
}
