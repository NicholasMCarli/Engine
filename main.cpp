#include<iostream>
#include<fstream>
#include <string>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"gameObject.cpp"

struct Shader {
public:
	Shader(std::string Vertex_shader_filepath)
	{
		std::string vertex_src{};
		std::fstream vertex_shader(Vertex_shader_filepath, std::ios::in | std::ios::out | std::ios::app);

		if (vertex_shader.fail())
		{
			std::cout << "Vertex Shader failed to open" << std::endl;
		}

		std::string line;
		while (std::getline(vertex_shader, line))
		{
			vertex_src += line + "/n";
		}
		std::cout << vertex_src << std::endl;
	};
};
int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int width{ 1000 };
	int height{ 600 };

	GLFWwindow* window = glfwCreateWindow( width,  height, "Niggas", NULL, NULL);
	if (!window)
	{
		std::cout << "window doesn't exist" << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	 
	glViewport(0, 0, 1000/2, 600/2);


	cube Cube;
	Shader shader("VertexShader.txt");
	// main loop
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.015, 0.1, 0.20, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwPollEvents();
		glfwSwapBuffers(window);

		glBindVertexArray(Cube.vao);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(&Cube.vertices));
	}
	// terminate all instances of window
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
