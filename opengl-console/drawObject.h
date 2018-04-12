#pragma once
#include "gl/gl3.h"
#include "transform.h"
#include "vector3.h"
#include "quaternion.h"

class drawobject
{
public:
	explicit drawobject();
	GLboolean load_data(const GLfloat *vertexs, const GLuint num_vertexs, const GLuint *elements, const GLuint num_elements);
	~drawobject();
	void unload();
	GLboolean draw(bool auto_load);
	vector3 position = vector3::zero;
	quaternion rotation = quaternion::zero;
	GLuint vao[1];
	GLuint vbo[1];
	GLuint ebo[1];
	GLuint count_element;
	GLboolean loaded;
};

