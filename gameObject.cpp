#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLM/glm.hpp>

struct gameObject
{
	std::string Name;
	glm::vec3 position{ };
	glm::vec3 rotation{ };
	unsigned int vao{ };
	unsigned int vbo{ };
	float vertices[3*3] = {};
public:
	virtual ~gameObject() {};
	void Draw()
	{
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	};
};

struct Cube : gameObject
{
	std::string Name = "Cube";
	float vertices[3*3] =
	{
		-0.5, -0.5, -0.5,
		 0.5, -0.5, -0.5,
		-0.5,  0.5, -0.5,

	};

	unsigned int vao{ };
	unsigned int vbo{ };
public:
	Cube()
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &vbo);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * 4, (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
};