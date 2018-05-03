#pragma once

class guid
{
public:
	guid();
	~guid();
	static int genid()
	{
		return currentid_++;
	}
private:
	static unsigned long currentid_;
};
unsigned long guid::currentid_ = 0;
