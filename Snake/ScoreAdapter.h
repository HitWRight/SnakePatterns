#pragma once
#include "Score.h"
#include "ScoreNew.h"
class ScoreAdapter: public ScoreBase, public ScoreNew{
public:
	static int GetScore();
	static void SaveScore();
	static std::vector<int> ReadScore();
	static void Increment(int points);
	static void FoodEaten();
	static void PowerupTaken();
	static int GetPowerupsTaken();
	static int GetFoodEaten();
};