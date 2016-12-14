#include "ScoreAdapter.h"

int ScoreAdapter::GetScore()
{
	return ScoreNew::GetScore();
}

void ScoreAdapter::PowerupTaken()
{
	Score::PowerupTaken();
}

void ScoreAdapter::FoodEaten()
{
	ScoreNew::FoodEaten();
}

void ScoreAdapter::SaveScore()
{
	return ScoreNew::SaveScore();
}

std::vector<int> ScoreAdapter::ReadScore()
{
	static vector<int> scores;
	ifstream input;
	input.open(FILE_SCORE); //TODO check if file exists
	while (input.good()) {
		int tempscore;
		input >> tempscore;
		scores.push_back(tempscore);
	}

	return scores;
}

void ScoreAdapter::Increment(int points)
{
	ScoreNew::Increment(points);
}

int ScoreAdapter::GetPowerupsTaken()
{
	return ScoreNew::GetPowerupsTaken();
}

int ScoreAdapter::GetFoodEaten()
{
	return ScoreNew::GetFoodEaten();
}