#pragma once
#include "gl/gl3.h"
#include "transform.h"
#include "vector3.h"
#include "quaternion.h"

class drawobject
{
public:
	explicit drawobject();
	void init_data(const GLfloat *v, const GLuint num_v, const GLuint *e, const GLuint num_e);
	~drawobject();
	GLboolean load();
	void unload();
	GLboolean draw(bool auto_load);
	const GLfloat* vertexs;
	GLuint num_vertex;
	const GLuint* elements;
	GLuint num_element;
	vector3 position = vector3::zero;
	quaternion rotation = quaternion::zero;
	GLuint vao[1];
	GLuint vbo[1];
	GLuint ebo[1];
	//enum buff_id
	//{
	//	vbo,
	//	ebo,
	//	num,
	//};
	//GLuint buff[buff_id::num];
	GLuint count_element;
	GLboolean loaded;
};

