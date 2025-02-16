#include "Heart.h"

void Heart::removeHeart() {
	hearts--;
}

bool Heart::hasHeartsLeft() {
	if (hearts > 0)
		return true;
	return false;
}