#pragma once

#include <vector>
#include <iostream>
#include "raylib.h"

class Heart
{
public:
	int hearts = 3;

	void removeHeart();
	bool hasHeartsLeft();
};