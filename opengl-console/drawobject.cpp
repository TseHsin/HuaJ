#include "DrawObject.h"
#include "GL3/gl3w.h"

drawobject::drawobject(const GLfloat* v, const GLuint* e) : vertexs(v), elements(e)
{
}

drawobject::~drawobject()
{
}

GLboolean drawobject::load()
{
	if (vertexs == nullptr || elements == nullptr || vao != 0)
	{
		return GL_FALSE;
	}
	glGenVertexArrays(1, vao);
	glGenBuffers(buff_id::num, buff);
	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ARRAY_BUFFER, buff[buff_id::vbo]);
	glBufferStorage(GL_ARRAY_BUFFER, sizeof(vertexs), vertexs, 0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, buff[buff_id::ebo]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buff[buff_id::ebo]);
	glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, 0);
	loaded = true;
	return true;
}

void drawobject::unload()
{
	glDeleteBuffers(1, vao);
	glDeleteBuffers(buff_id::num, buff);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buff[buff_id::ebo]);
	glDrawElements(GL_TRIANGLES, count_element, GL_UNSIGNED_INT, nullptr);
	return GL_TRUE;
}
