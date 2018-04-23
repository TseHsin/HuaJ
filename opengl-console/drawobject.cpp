#include "DrawObject.h"
#include "GL/GL.h"
#include "GL3/gl3w.h"
#include "Cg/cg.h"
#include "Cg/cgGL.h"
#include "GL/glut.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "LoadShaders.h"

drawobject::drawobject()
{
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

GLboolean drawobject::load_data(const GLfloat* vertexs, const GLuint num_vertex, const GLuint* elements,
                                const GLuint num_element)
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

GLvoid drawobject::load_shader(const char* vertex_shader_path, const char* frag_shader_path)
{
	cg_context = cgCreateContext();
	cgGLSetDebugMode(CG_TRUE);
	cgSetParameterSettingMode(cg_context, CG_DEFERRED_PARAMETER_SETTING);
	vertex_profile = cgGLGetLatestProfile(CG_GL_VERTEX);
	cgGLSetOptimalOptions(vertex_profile);
	vertex_program = cgCreateProgramFromFile(cg_context, CG_SOURCE, "../bin/shaders/vs.cg", vertex_profile, "vs_main", nullptr);
	cgGLLoadProgram(vertex_program);
	frag_profile = cgGLGetLatestProfile(CG_GL_FRAGMENT);
	cgGLSetOptimalOptions(frag_profile);
	frag_program = cgCreateProgramFromFile(cg_context, CG_SOURCE, "../bin/shaders/fs.cg", frag_profile, "fs_main", nullptr);
	cgGLLoadProgram(frag_program);

	ShaderInfo shader_info[] = {
		{GL_VERTEX_SHADER, vertex_shader_path},
		{GL_FRAGMENT_SHADER, frag_shader_path},
		{GL_NONE, nullptr}
	};
	render_prog = LoadShaders(shader_info);
}

GLuint drawobject::get_location_ptr(const char* location) const
{
	//glUseProgram(render_prog);
	//return glGetUniformLocation(render_prog, location);
	return 0;
}

void drawobject::unload()
{
	glDeleteBuffers(1, vao);
	glDeleteBuffers(1, vbo);
	glDeleteBuffers(1, ebo);
	loaded = GL_FALSE;
}

GLboolean drawobject::draw(const bool auto_load)
{
	if (!loaded)
	{
		return GL_FALSE;
	}

	static float angle;
	angle += 10;

	cgGLBindProgram(vertex_program);
	cgGLEnableProfile(vertex_profile);
	cgGLBindProgram(frag_program);
	cgGLEnableProfile(frag_profile);

	const auto model = glm::mat4(1.0f);
	const auto view = glm::lookAt(
		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));
	const auto proj = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
	auto mvp_mat4 = proj * view * model;
	//glUseProgram(render_prog);
	//const auto uni_mvp = glGetUniformLocation(render_prog, "mvp");
	//glUniformMatrix4fv(uni_mvp, 1, GL_FALSE, value_ptr(mvp_mat4));
	//const auto uni_offset = glGetUniformLocation(render_prog, "offset");
	//glUniform3f(uni_offset, 0.0, 0.0, 0.0);

	const auto mvp = cgGetNamedParameter(vertex_program, "MVP");
	cgGLSetStateMatrixParameter(mvp, CG_GL_MODELVIEW_PROJECTION_MATRIX, CG_GL_MATRIX_IDENTITY);
	cgGLSetMatrixParameterfc(mvp, glm::value_ptr(mvp_mat4));
	
	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
	glDrawElements(GL_TRIANGLES, count_element, GL_UNSIGNED_INT, nullptr);
	
	cgGLDisableProfile(vertex_profile);
	cgGLDisableProfile(frag_profile);
	return GL_TRUE;
}
