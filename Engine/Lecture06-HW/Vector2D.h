#pragma once
#include "math.h"

struct Vector2D
{
	double x;
	double y;

	explicit Vector2D() : x(0), y(0) {}
	explicit Vector2D(double x_, double y_) : x(x_), y(y_) {}

	bool operator== (const Vector2D& rhs) const
	{
		return (x == rhs.x && y == rhs.y);
	}

	bool operator!= (const Vector2D& rhs) const
	{
		return (x != rhs.x && y != rhs.y);
	}

	bool operator< (const Vector2D& rhs) const
	{
		return (x != rhs.x ? x < rhs.x : y < y < rhs.y);
	}

	Vector2D operator+ (const Vector2D& rhs) const
	{
		return Vector2D(x + rhs.x, y + rhs.y);
	}

	Vector2D operator- (const Vector2D& rhs) const
	{
		return Vector2D(x - rhs.x, y - rhs.y);
	}

	Vector2D operator* (double rhs) const
	{
		return Vector2D(x * rhs, y * rhs);
	}

	Vector2D operator/ (double rhs) const
	{
		return Vector2D(x / rhs, y / rhs);
	}

	double norm() const { return hypot(x, y); }

	//방향이 같은 단위 벡터를 반환한다.
	Vector2D normalize() const {
		return Vector2D(x / norm(), y / norm());
	}
};