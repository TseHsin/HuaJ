// opengl_console.cpp: 定义控制台应用程序的入口点。
//

#include "vgl.h"
#include <LoadShaders.h>
#include "drawmanage.h"

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
	cube_ptr = drawmanage::instance()->add_draw(cube);
}

void display_fun()
{
	const float black[] = {0.5f, 0.5f, 0.0f, 0.0f};
	glClearBufferfv(GL_COLOR, 0, black);
	drawmanage::instance()->draw(cube_ptr);
}

int main(int argc, char** argv)
{
	glfwInit();
	const auto window = glfwCreateWindow(1024, 512, "OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	gl3wInit();
	init_fun();

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
