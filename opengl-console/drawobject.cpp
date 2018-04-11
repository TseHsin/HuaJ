#include "DrawObject.h"
#include "GL3/gl3w.h"

drawobject::drawobject()
{
}

void drawobject::init_data(const GLfloat *v, const GLuint num_v, const GLuint *e, const GLuint num_e)
{
	vertexs = v;
	num_vertex = num_v;
	elements = e;
	num_element = num_e;
}

drawobject::~drawobject()
{
	//unload();
	//delete[] vao;
	//delete[] buff;
	//delete vertexs;
	//delete elements;
	//delete &position;
	//delete &rotation;
}

GLboolean drawobject::load()
{
	if (vertexs == nullptr || elements == nullptr)
	{
		return GL_FALSE;
	}
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);
	glCreateBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferStorage(GL_ARRAY_BUFFER, num_vertex, vertexs, 0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);
	
	glGenBuffers(1, ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
	glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, num_element, elements, 0);
	count_element = num_element / sizeof(GLuint);

	loaded = true;
	return GL_TRUE;
}

void drawobject::unload()
{
	glDeleteBuffers(1, vao);
	//glDeleteBuffers(buff_id::num, buff);

	loaded = GL_FALSE;
}

GLboolean drawobject::draw(const bool auto_load)
{
	if (!loaded)
	{
		if (auto_load)
		{
			load();
		}
		else
		{
			return GL_FALSE;
		}
	}
	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
	glDrawElements(GL_TRIANGLES, count_element, GL_UNSIGNED_INT, nullptr);
	return GL_TRUE;
}
