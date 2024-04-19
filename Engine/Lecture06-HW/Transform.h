#pragma once
#include "Vector2D.h"

class Transform
{
public:
	Transform();
	virtual ~Transform();

	const Vector2D& GetPosition() { return _position; }
	void SetPosition(const Vector2D& position) { _position = position; }

	const Vector2D& GetScale() { return _scale; }
	void SetScale(const Vector2D& scale) { _scale = scale; }

private:
	Vector2D _position;
	Vector2D _scale;
};
