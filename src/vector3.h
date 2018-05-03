#pragma once

class vector3
{
public:
	explicit vector3(float x = 0, float y = 0, float z = 0);
	~vector3();

	vector3 normalize() const;
	vector3 clone() const;
	static vector3 cross(const vector3& v0, const vector3& v1);
	static float dot(const vector3& v0, const vector3& v1);

	float length() const;
	bool operator ==(const vector3& v) const;
	bool operator !=(const vector3& v) const;
	vector3 operator +(const vector3& v) const;
	vector3 operator -(const vector3& v) const;
	vector3 operator *(const float f) const;
	vector3 operator /(const float f) const;
	vector3 operator -() const;
	vector3& operator +=(const vector3& v);
	vector3& operator -=(const vector3& v);
	vector3& operator *=(const float f);
	vector3& operator /=(const float f);
	float operator [](int index) const;

	static vector3 zero;
	static vector3 one;
	static vector3 up;
	static vector3 right;
	static vector3 forward;

	float x;
	float y;
	float z;
	float raw[3]{ x, y, z };
};
