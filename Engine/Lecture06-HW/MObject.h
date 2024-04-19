#pragma once
#include "Transform.h"
class MObject
{
public:
	MObject();
	~MObject();

	virtual void update();
	virtual void render();

	Transform transform;
};
