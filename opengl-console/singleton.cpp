#include "singleton.h"


template<class T>
singleton<T>::singleton()
{
}

template<class T>
singleton<T>::~singleton()
{
}

template <class T>
T singleton<T>::instance()
{
	if (has_instance_)
		return instance_;

	instance_ = new T();
	has_instance_ = true;
	return instance_;
}

