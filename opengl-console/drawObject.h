#pragma once
#include "gl/gl3.h"
#include "transform.h"
#include "vector3.h"
#include "quaternion.h"

class drawobject
{
public:
	explicit drawobject(const GLfloat *v = nullptr, const GLuint *e = nullptr);
	~drawobject();
	GLboolean load();
	void unload();
	GLboolean draw(bool auto_load);
	const GLfloat* vertexs;
	const GLuint* elements;
	const vector3 position = vector3::zero;
	const quaternion rotation = quaternion::zero;
	GLuint vao[1];
	enum buff_id
	{
		vbo,
		ebo,
		num,
	};
	GLuint buff[buff_id::num];
	GLuint count_element;
	GLboolean loaded;
};

