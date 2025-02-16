#include "Basket.h"


void Basket::draw() {
	DrawRectangle(position.x, position.y, width, height, BROWN);
}
void Basket::update() {
	Vector2 pos = { GetMouseX() - (width / 2), 500 };
	position = pos;
}