#pragma once
#include "vector3.h"
#include <cmath>
#include <exception>

vector3 vector3::zero = vector3();
vector3 vector3::one = vector3(1, 1, 1);
vector3 vector3::right = vector3(1, 0, 0);
vector3 vector3::up = vector3(0, 1, 0);
vector3 vector3::forward = vector3(0, 0, 1);

vector3::vector3(const float x, const float y, const float z) : x(x), y(y), z(z)
{
}

vector3::~vector3()
{
}

vector3 vector3::normalize() const
{
	auto len = length();
	if (len == 0)
	{
		return zero;
	}
	return vector3(x / len, y / len, z / len);
}

vector3 vector3::clone() const
{
	return vector3(x, y, z);
}

vector3 vector3::cross(const vector3& v0, const vector3& v1)
{
	return vector3(
		v0.y * v1.z - v0.z * v1.y,
		v0.z * v1.x - v0.x * v1.z,
		v0.x * v1.y - v0.y * v1.x
	);
}

float vector3::dot(const vector3& v0, const vector3& v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z + v1.z;
}

float vector3::length() const
{
	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

bool vector3::operator==(const vector3& v) const
{
	return x == v.x && y == v.y && z == v.z;
}

bool vector3::operator!=(const vector3& v) const
{
	return x != v.z || y != v.y || z != v.z;
}

vector3 vector3::operator+(const vector3& v) const
{
	return vector3(x + v.x, y + v.y, z + v.z);
}

vector3 vector3::operator-(const vector3& v) const
{
	return vector3(x - v.x, y - v.y, z - v.z);
}

vector3 vector3::operator*(const float f) const
{
	return vector3(x * f, y * f, z * f);
}

vector3 vector3::operator/(const float f) const
{
	if (f == 0)
	{
		throw std::exception("target could not be zero");
	}
	return vector3(x / f, y / f, z / f);
}

vector3 vector3::operator-() const
{
	return vector3(-x, -y, -z);
}

vector3& vector3::operator+=(const vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

vector3& vector3::operator-=(const vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

vector3& vector3::operator*=(const float f)
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

vector3& vector3::operator/=(const float f)
{
	x /= f;
	y /= f;
	z /= f;
	return *this;
}

float vector3::operator[](const int index) const
{
	switch (index)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		throw new std::exception("out of rang");
	}
}
