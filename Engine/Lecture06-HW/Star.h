#pragma once
#include "MObject.h"

struct Color
{
	float r;
	float g;
	float b;
};

class Star : public MObject
{
public:
	Star() {};
	~Star() {};

	Color color = { 1, 1, 1 };

	void update() override;
	void render() override;
};