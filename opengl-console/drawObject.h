#pragma once
#include "gl/gl3.h"
#include "transform.h"
#include "vector3.h"
#include "quaternion.h"
#include <Cg/cg.h>

class drawobject
{
public:
	explicit drawobject();
	GLboolean load_data(const GLfloat *vertexs, const GLuint num_vertexs, const GLuint *elements, const GLuint num_elements);
	GLvoid load_shader(const char *vertex_shader_path, const char *frag_shader_path);
	GLuint get_location_ptr(const char *location) const;
	
	~drawobject();
	GLvoid unload();
	GLboolean draw(bool auto_load);
	vector3 position = vector3::zero;
	quaternion rotation = quaternion::zero;
	GLuint vao[1];
	GLuint vbo[1];
	GLuint ebo[1];
	GLuint count_element;
	GLboolean loaded;
	GLuint render_prog;

	CGcontext cg_context;
	CGprofile vertex_profile;
	CGprofile frag_profile;
	CGprogram vertex_program;
	CGprogram frag_program;
};

