#include "ScoreNew.h"
#include "Settings.h"
#include <vector>

ScoreNew::ScoreNew()
{
}

ScoreNew::~ScoreNew()
{
}
int ScoreNew::score;
int ScoreNew::powerupsTaken;
int ScoreNew::foodEaten;

int ScoreNew::GetScore()
{
	return score;
}

void ScoreNew::PowerupTaken()
{
	Increment(5);
	powerupsTaken++;
}

void ScoreNew::FoodEaten()
{
	Increment(1);
	foodEaten++;
}

void ScoreNew::Increment(int points) {
	ScoreNew::score += (points*100);
}

void ScoreNew::SaveScore()
{

	fstream output;
	output.open(FILE_SCORE, std::fstream::out);
	output << score << endl;
	output.close();

}

std::vector<int> ScoreNew::ReadScore()
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

int ScoreNew::GetPowerupsTaken()
{
	return powerupsTaken;
}

int ScoreNew::GetFoodEaten()
{
	return foodEaten;
}

