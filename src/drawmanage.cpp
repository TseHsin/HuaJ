#include "vgl.h"
#include "drawManage.h"
#include "drawobject.h"

bool drawmanage::draw(const GLuint64 draw_ptr)
{
	if (draw_ptr >= all_draw_.size())
	{
		return false;
	}
	return all_draw_[draw_ptr].draw(true);
}

GLuint64 drawmanage::add_draw(drawobject& draw)
{
	all_draw_.push_back(draw);
	return all_draw_.size() - 1;
}

drawmanage::~drawmanage()
{
	delete &all_draw_;
}

drawmanage::drawmanage()
{
}

bool drawmanage::hasinit_ = false;
drawmanage* drawmanage::instance_ = nullptr;
