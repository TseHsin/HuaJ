#pragma once
#include "quaternion.h"
#include <cmath>

quaternion quaternion::zero = quaternion(0, 0, 0, 1);

quaternion::quaternion(const float x, const float y, const float z, const float w)
{
	this->set(x, y, z, w);
}

quaternion::~quaternion()
{
}

void quaternion::set(const float x, const float y, const float z, const float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

bool quaternion::equals(quaternion& other) const
{
	return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
}

void quaternion::normalize()
{
	const auto mag = sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2) + powf(w, 2));
	this->x /= mag;
	this->y /= mag;
	this->z /= mag;
	this->w /= mag;
}

quaternion quaternion::angle_axis(const float angle, vector3& axis)
{
	const auto angle_half = angle * 0.5f;
	const auto cos_angle = cosf(angle_half);
	const auto sing_angle = sinf(angle_half);
	return quaternion(cos_angle, sing_angle * axis.x, sing_angle * axis.y, sing_angle * axis.z);
}

quaternion quaternion::euler(vector3& euler)
{
	auto angle_half = euler.x * 0.5f;
	const auto sin_x = sinf(angle_half);
	const auto cos_x = cosf(angle_half);
	angle_half = euler.y * 0.5f;
	const auto sin_y = sinf(angle_half);
	const auto cos_y = cosf(angle_half);
	angle_half = euler.z * 0.5f;
	const auto sin_z = sinf(angle_half);
	const auto cos_z = sinf(angle_half);
	const auto x = sin_x * cos_y * cos_z - cos_x * sin_y * sin_z;
	const auto y = cos_x * sin_y * cos_z + sin_x * cos_y * sin_z;
	const auto z = cos_x * cos_y * sin_z - sin_x * sin_y * cos_z;
	const auto w = cos_x * cos_y * cos_z + sin_x * sin_y * sin_z;
	return  quaternion(x, y, z, w);
}

quaternion quaternion::inverse(quaternion& rotation)
{
	return quaternion(-rotation.x, -rotation.y, -rotation.z, rotation.w);
}

quaternion quaternion::lerp(quaternion& a, quaternion& b, const float t)
{
	const auto back_t = 1 - t;
	return quaternion(back_t * a.x + t * b.x, back_t * a.y + t * b.y, back_t * a.z + t * b.z, back_t * a.w + t * b.w);
}

quaternion quaternion::slerp(quaternion& a, quaternion& b, float t)
{
	const auto back_t = 1 - t;
	const auto theta = acosf(a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
	const auto sin_theta = sinf(theta);
	const auto wa = sin(back_t * theta) / sin_theta;
	const auto wb = sin(t * theta) / sin_theta;
	return quaternion(wa*a.x + wb * b.x, wa*a.y + wb * b.y, wa*a.z + wb * b.z, wa*a.w + wb * b.w);
}

