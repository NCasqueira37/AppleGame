#include "Apple.h"


void Apple::spawnApple(std::vector<Apple>& apples, int width) {
	// Set random position at top of screen + an offset
	position = Vector2{ (float)GetRandomValue(20, width), (float)GetRandomValue(-25,-10) };

	// Set random apple speed
	speed = GetRandomValue(50, 250);

	// Set random apple size radius
	radius = GetRandomValue(10, 30);

	// add apple to vector
	apples.push_back(*this);
}

void Apple::draw() {
	DrawCircle(position.x, position.y, radius, RED);
}

void Apple::update() {
	position.y += speed * GetFrameTime();
}

void Apple::deleteApple(std::vector<Apple>& apples, Heart& heart) {
	for (auto it = apples.begin(); it != apples.end();) {
		if (it->position.y>GetScreenHeight()) {
			it = apples.erase(it);
			heart.removeHeart();
		}
		else {
			++it;
		}
	}

}

void Apple::catchApple(std::vector<Apple>& apples, Vector2 basketPos, int& score) {
	for (auto it = apples.begin(); it != apples.end();) {
		if (it->position.x + it->radius >= basketPos.x - 50 && it->position.x - it->radius <= basketPos.x + 50 &&
			it->position.y + it->radius >= basketPos.y - 10 && it->position.y - it->radius <= basketPos.y + 10) {
			it = apples.erase(it);
			score++;
		}
		else {
			++it;
		}
	}
}