#pragma once

template<class T>
class singleton
{
public:
	~singleton();
	T instance();
private:
	singleton();
	bool has_instance_ = fals;
	T instance_;
};


