#pragma once
#include "Settings.h"
#include "ScoreBase.h"
#include <vector>

static class Score : public ScoreBase {
private:
	static int score;
	static int powerupsTaken;
	static int foodEaten;
public:
	static void PowerupTaken();
	static void FoodEaten();
	static void Increment(int points);
	static int GetScore();
	static void SaveScore();
	static std::vector<int> ReadScore();
	static int GetPowerupsTaken();
	static int GetFoodEaten();
};