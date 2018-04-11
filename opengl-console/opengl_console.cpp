// opengl_console.cpp: 定义控制台应用程序的入口点。
//

#include "vgl.h"
#include <LoadShaders.h>
#include "drawmanage.h"

enum vao_ids
{
	triangle_attrib,
	cube_attrib,
	num_vao,
};

enum vbo_ids
{
	triangle_buffer,
	cube_buffer,
	num_vbo,
};

enum ebo_ids
{
	cube_element,
	num_ebo,
};

enum attrib_ids { v_position = 0 };

GLuint vao[num_vao];
GLuint vbo[num_vbo];
GLuint ebo[num_ebo];
GLuint count_cube_element;

void init_fun()
{
	glGenVertexArrays(num_vao, vao);

	glBindVertexArray(vao[triangle_attrib]);
	GLfloat vertexs_triangle[3][2] = {
		{0, 0},
		{1, 0},
		{0, 1}
	};
	glCreateBuffers(num_vbo, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[triangle_buffer]);
	glBufferStorage(GL_ARRAY_BUFFER, sizeof(vertexs_triangle), vertexs_triangle, 0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);

	glBindVertexArray(vao[cube_attrib]);
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
	glBindBuffer(GL_ARRAY_BUFFER, vbo[cube_buffer]);
	glBufferStorage(GL_ARRAY_BUFFER, sizeof(vertex_cube), vertex_cube, 0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);
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
	count_cube_element = sizeof(element_cube) / sizeof(GLuint);
	glGenBuffers(num_ebo, ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[cube_element]);
	glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, sizeof(element_cube), element_cube, 0);

	auto cube = drawobject(vertex_cube, element_cube);
	auto cube_p = drawmanage::instance()->add_draw(cube);
}

void display_fun()
{
	const float black[] = {0.5f, 0.5f, 0.0f, 0.0f};
	glClearBufferfv(GL_COLOR, 0, black);
	glBindVertexArray(vao[triangle_attrib]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(vao[cube_attrib]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[cube_element]);
	glDrawElements(GL_TRIANGLES, count_cube_element, GL_UNSIGNED_INT, nullptr);
}

int main(int argc, char** argv)
{
	drawobject obj(nullptr, nullptr);
	drawmanage::instance()->add_draw(obj);

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
