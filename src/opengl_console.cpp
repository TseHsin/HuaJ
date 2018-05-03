#include <GL3/gl3.h>
#include <GL/gl.h>
#include "GL3/gl3w.h"
#include <GLFW/glfw3.h>
#include "drawManage.h"


GLuint64 cube_ptr;

void init_fun()
{
	GLfloat vertex_cube[] = {
		0, 0, 0,
		1, 0, 0,
		1, 1, 0,
		0, 1, 0,
		0, 0, 1,
		1, 0, 1,
		1, 1, 1,
		0, 1, 1
	};
	GLuint element_cube[] = {
		0, 1, 2,
		0, 2, 3,
		4, 5, 1,
		4, 1, 0,
		7, 4, 0,
		7, 0, 3,
		6, 1, 5,
		6, 2, 1,
		4, 6, 5,
		4, 7, 6,
		7, 2, 6,
		7, 3, 2,
	};
	drawobject cube;
	cube.load_data(vertex_cube, sizeof(vertex_cube), element_cube, sizeof(element_cube));
	cube.load_shader("../bin/shaders/standard/v.glsl", "../bin/shaders/standard/f.glsl");
	cube_ptr = drawmanage::instance()->add_draw(cube);
}

void display_fun()
{
	//const float black[] = {0.5f, 0.5f, 0.0f, 0.0f};
	//glClearBufferfv(GL_COLOR, 0, black);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f, 0.5f, 0.0f, 0.0f);
	drawmanage::instance()->draw(cube_ptr);
}

void reshape(GLFWwindow *window, int w, int h)
{
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(45, static_cast<float>(w) / static_cast<float>(h), 0.1, 100);
	//glViewport(0, 0, w, h);
	glViewport(0, 0, w, h);
	
}

int main(int argc, char** argv)
{
	glfwInit();
	const auto window = glfwCreateWindow(512, 512, "OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	gl3wInit();
	glfwSetWindowSizeCallback(window, reshape);
	init_fun();
	glDisable(GL_CULL_FACE);

	while (!glfwWindowShouldClose(window))
	{
		display_fun();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
