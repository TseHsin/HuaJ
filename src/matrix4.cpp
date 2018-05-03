#include "matrix4.h"



matrix4::matrix4()
{
}

matrix4::~matrix4()
{
}

float* matrix4::operator[](const int index)
{
	if (index < 0 || index > 4)
	{
		return nullptr;
	}
	return data_[index];
}

matrix4 matrix4::frustum(const float left, const float right, const float bottom, const float top, const float n, const float f)
{
	auto ret = matrix4::one();
	if (left == right || bottom == top || n == f || n < 0.0f || f < 0.0f)
	{
		return ret;
	}
	ret[0][0] = (2.0f * n) / (right - left);
	ret[1][1] = (2.0f * n) / (top - bottom);
	
	ret[2][0] = (left + right) / (right - left);
	ret[2][1] = (top + bottom) / (top - bottom);
	ret[2][2] = (f + n) / (n - f);
	ret[2][3] = -1.0f;

	ret[3][2] = (2.0f * f * n) / (n - f);
	ret[3][3] = 0.0f;

	return ret;
}

matrix4 matrix4::one()
{
	matrix4 ret;
	for (auto i = 0; i < 4; i++)
		ret[i][i] = 1;
	return ret;
}
