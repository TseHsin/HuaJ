#pragma once
#include "drawobject.h"
#include <map>
#include <vector>

class drawmanage
{
public:
	static drawmanage* instance()
	{
		if (hasinit_)
		{
			return instance_;
		}
		hasinit_ = true;
		instance_ = new drawmanage();
		return instance_;
	}
	bool draw(GLuint64 draw_ptr);
		
	GLuint64 add_draw(drawobject& draw);

	~drawmanage();


private:
	static bool hasinit_;
	static drawmanage *instance_;

	drawmanage();
	std::vector<drawobject> all_draw_;
};


