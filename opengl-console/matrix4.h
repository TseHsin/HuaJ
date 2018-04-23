#pragma once
class matrix4
{
public:
	matrix4();
	~matrix4();
	float* operator[](int index);
	static matrix4 frustum(float left, float right, float bottom, float top, float n, float f);

	static matrix4 one();

private:
	float data_[4][4];
};
