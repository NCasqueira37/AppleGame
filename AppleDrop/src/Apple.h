#pragma once

#include "raylib.h"
#include <vector>
#include <iostream>
#include "Heart.h"

class Apple
{
public:

	Apple() = default;

	Vector2 position;
	Vector2 offset = { 20,20 };
	float speed;
	float radius;

	void spawnApple(std::vector<Apple>& apples, int width);
	static void deleteApple(std::vector<Apple>& apples, Heart& heart);
	static void catchApple(std::vector<Apple>& apples, Vector2 basketPos, int& score);
	void draw();
	void update();
};