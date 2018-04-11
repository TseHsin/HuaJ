#include "stdafx.h"
#include "gl_window.h"
#include "gl/glut.h"


gl_window::gl_window()
{
}


gl_window::~gl_window()
{
}


void gl_window::show(int* argc, char** args) const
{
	if (init_fun != nullptr)
	{
		init_fun();
	}
	glutInit(argc, args);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(1024, 512);
	glutCreateWindow("Test Windows");

	if (display_fun != nullptr)
	{
		glutDisplayFunc(display_fun);
	}
	glutMainLoop();
}
