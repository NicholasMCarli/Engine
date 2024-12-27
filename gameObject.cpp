#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLM/glm.hpp>

#define glGenVertexArrays
#define glGenBuffers

struct gameObject
{
	glm::vec3 position{ };
	glm::vec3 rotation{ };
};

struct cube : gameObject
{
	float vertices[9] = 
	{
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0,
		-0.5,  0.5, 0.0,

	};

	unsigned int vao{ };
	unsigned int vbo{ };
public:
	cube()
	{
		glGenVertexArrays(1, &cube::vao);
		glGenBuffers(1, &cube::vbo);

		glBindBuffer(GL_ARRAY_BUFFER, cube::vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cube::vbo), vertices, GL_STATIC_DRAW);


		glVertexAttribIPointer(0, 3, GL_FALSE, 3 * 4 , (void*)0);
		glEnableVertexAttribArray(0);
	}
};