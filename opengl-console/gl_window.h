#pragma once
class gl_window
{
public:
	gl_window();
	~gl_window();

	void show(int* argv, char** args) const;
	
	void(*display_fun)();
	void(*init_fun)();
};

