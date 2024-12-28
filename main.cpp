#include<iostream>
#include<fstream>
#include <string>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"gameObject.cpp"

struct Scene
{
	gameObject* gameObjects{};
	unsigned int numGameObjects{ };
public:
	void render_scene()
	{
		for (int i = 0; i < numGameObjects; i++)
		{
			glBindVertexArray(gameObjects[i].vao);
			glDrawArrays(GL_TRIANGLES, 0, sizeof(&gameObjects[i].vertices));
		}
	};
};

struct Shader {
	mutable std::string vertex_shader_src{ };
public:
	Shader()
	{

		vertex_shader_src = get_shader_file("VertexShader.glsl");
		std::cout << vertex_shader_src << std::endl;

		const char* vertex_shader_src_cstr = vertex_shader_src.c_str();

		unsigned int shader_program = glCreateProgram();
		unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertex_shader, 1, vertex_shader_src_cstr, NULL);
		glCompileShader(vertex_shader);
	};

	std::string get_shader_file(std::string filepath)
	{
		std::string file_src{};
		std::fstream File(filepath, std::ios::in | std::ios::out | std::ios::app);

		if (File.fail())
		{
			std::cout << "File failed to open" << std::endl;
			return "Failed";
		}
		else
		{
			std::cout << "File opened successfully" << std::endl;
		}

		std::string line;
		while (std::getline(File, line))
		{
			file_src += line + "\n";
		}
		return file_src;
	};
	unsigned int get_shader()
	{
		return 1;
	}
	
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

	cube Cube;
	Shader Shader;
	 
	glViewport(0, 0, 1000, 600);


	// main loop
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.015, 0.1, 0.20, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwPollEvents();
		glfwSwapBuffers(window);

		glBindVertexArray(Cube.vao);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(&Cube.vertices));
		glUseProgram(Shader.get_shader());
	}
	// terminate all instances of window
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
