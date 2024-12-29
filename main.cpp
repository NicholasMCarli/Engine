#include<iostream>
#include<fstream>
#include <string>
#include <type_traits>
#include <vector>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"gameObject.cpp"

struct Scene
{
<<<<<<< HEAD
	std::vector<gameObject*> gameObjects = {  };
	 int numGameObjects{ };
public:
	void render_scene()
	{
		int numGameObjects = gameObjects.size();
		for (int i = 0; i < numGameObjects; i++)
		{
			gameObject* obj = gameObjects[i]; 

			if (obj)
			{
				obj->Draw();
			}
=======
	gameObject* gameObjects{};
	unsigned int numGameObjects{ };
public:
	void render_scene()
	{
		for (int i = 0; i < numGameObjects; i++)
		{
			glBindVertexArray(gameObjects[i].vao);
			glDrawArrays(GL_TRIANGLES, 0, sizeof(&gameObjects[i].vertices));
>>>>>>> 40386bebb0a9c6de959c7ec61e5a1a2fba0a9ab9
		}
	};
};

struct Shader {
<<<<<<< HEAD
	unsigned int shader{};
	 std::string vertex_shader_src{ };
	 std::string Fragment_shader_src{ };
=======
	mutable std::string vertex_shader_src{ };
>>>>>>> 40386bebb0a9c6de959c7ec61e5a1a2fba0a9ab9
public:
	Shader()
	{

		vertex_shader_src = get_shader_file("VertexShader.glsl");
<<<<<<< HEAD
		Fragment_shader_src = get_shader_file("FragmentShader.glsl");
		const char* vertex_shader_src_char = vertex_shader_src.c_str();
		const char* Fragment_shader_src_char = Fragment_shader_src.c_str();
		std::cout << vertex_shader_src << std::endl;


		unsigned int shader_program = glCreateProgram();
		unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		unsigned int Fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertex_shader, 1, &vertex_shader_src_char, NULL);
		glShaderSource(Fragment_shader, 1, &Fragment_shader_src_char, NULL);
		glCompileShader(vertex_shader);
		glCompileShader(Fragment_shader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
			std::cerr << "Error: Vertex Shader Compilation Failed\n" << infoLog << std::endl;
		}

		glAttachShader(shader_program, vertex_shader);
		glAttachShader(shader_program, Fragment_shader);
		glLinkProgram(shader_program);

		
		shader = shader_program;
=======
		std::cout << vertex_shader_src << std::endl;

		const char* vertex_shader_src_charStr = vertex_shader_src.c_str();

		unsigned int shader_program = glCreateProgram();
		unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertex_shader, 1,&vertex_shader_src_charStr, NULL);
		glCompileShader(vertex_shader);
>>>>>>> 40386bebb0a9c6de959c7ec61e5a1a2fba0a9ab9
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
<<<<<<< HEAD
		return shader;
=======
		return 1;
>>>>>>> 40386bebb0a9c6de959c7ec61e5a1a2fba0a9ab9
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

<<<<<<< HEAD
=======
	cube Cube;
	Shader Shader;
>>>>>>> 40386bebb0a9c6de959c7ec61e5a1a2fba0a9ab9
	 
	glViewport(0, 0, 1000, 600);


<<<<<<< HEAD
	Scene scene;
	cube* Cube = new cube;
	Shader shader;

	Cube->Name = "Cube";

	scene.gameObjects.push_back(Cube);


	if (std::is_base_of<gameObject, cube>::value) {
		std::cout << "cube inherits from gameObject\n";
	}
	else {
		std::cout << "cube does not inherit from gameObject\n";
	}

=======
>>>>>>> 40386bebb0a9c6de959c7ec61e5a1a2fba0a9ab9
	// main loop
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.015, 0.1, 0.20, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		glUseProgram(shader.get_shader());

		scene.render_scene();

		glfwPollEvents();
		glfwSwapBuffers(window);
<<<<<<< HEAD
=======

		glBindVertexArray(Cube.vao);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(&Cube.vertices));
		glUseProgram(Shader.get_shader());
>>>>>>> 40386bebb0a9c6de959c7ec61e5a1a2fba0a9ab9
	}
	// terminate all instances of window
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
