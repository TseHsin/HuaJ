#pragma once
#include "vector3.h"

class quaternion
{
public:
	explicit quaternion(float x = 0, float y = 0, float z = 0, float w = 0);
	~quaternion();
	void set(float x, float y, float z, float w);
	bool equals(quaternion& other) const;
	void normalize();
	float x;
	float y;
	float z;
	float w;
	static quaternion angle_axis(float angle, vector3& axis);
	static quaternion euler(vector3& euler);
	static quaternion inverse(quaternion& rotation);
	static quaternion lerp(quaternion& a, quaternion& b, float t);
	static quaternion slerp(quaternion& a, quaternion& b, float t);
	static quaternion zero;
};
