#include "raylib.h"
#include "Apple.h"
#include <vector>
#include <string>
#include "Basket.h"
#include "Heart.h"
#include "GameManager.h"

#define WIDTH 800
#define HEIGHT 800

#define APPLE_SPAWN_RATE 1

int main() {
	InitWindow(800, 600, "Apple Game");
	SetTargetFPS(60);

	Camera2D cam{ Vector2{0,0}, Vector2{0,0}, 0, 1 };

	// Create gamemanager to keep track state of game
	GameManager gameManager{};
	gameManager.state = GameManager::RUNNING;

	// All apples
	std::vector<Apple> apples;

	// User's basket
	Basket basket;

	// User's score
	int score = 0;

	// hearts and texture for heart
	Texture2D heartText = LoadTexture("data/Heart.png");
	Heart heart;

	// Timer for spawning apples
	float timer = 0;

	while (!WindowShouldClose()) {
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode2D(cam);

		switch (gameManager.state)
		{
		case GameManager::RUNNING:
			// Draw hearts
			for (int i = 0; i < heart.hearts; i++) {
				Rectangle source{ 0, 0, heartText.width, heartText.height };
				Rectangle dest{ (i * 50) , 150, 50, 50 };
				DrawTexturePro(heartText, source, dest, Vector2{ 0,0 }, 0, WHITE);
			}

			// Draw and update apples
			for (auto& a : apples) {
				a.draw();
				a.update();
			}
			// draw basket
			basket.draw();

			// draw score and FPS
			DrawText(("Score: " + std::to_string(score)).c_str(), 10, 40, 20, BLACK);
			DrawFPS(10, 10);

			// Check when game over then switch states
			if (!heart.hasHeartsLeft()) {
				gameManager.state = GameManager::GAMEOVER;
			}

			basket.update();

			timer -= GetFrameTime();
			if (timer < 0) {
				Apple apple;
				apple.spawnApple(apples, WIDTH);
				timer = APPLE_SPAWN_RATE;
			}

			Apple::catchApple(apples, basket.position, score);
			Apple::deleteApple(apples, heart);
			break;
		case GameManager::GAMEOVER:
			DrawText("GAME OVER!", WIDTH / 4, HEIGHT / 4, 60, BLACK);
			DrawText(("Score: " + std::to_string(score)).c_str(), WIDTH / 4, (HEIGHT / 4) + 100, 60, BLACK);
			break;

		default:
			break;
		}

		EndMode2D();
		EndDrawing();
	}
}