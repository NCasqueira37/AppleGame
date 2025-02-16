#pragma once

#include "raylib.h"

class Basket
{
public:
	Basket() = default;

	Vector2 position;
	int width = 100;
	int height = 20;

	void draw();
	void update();
};