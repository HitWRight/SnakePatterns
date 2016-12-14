#pragma once
#include <fstream>
#include <vector>
using namespace std;
class ScoreNew
{
public:
	ScoreNew();
	~ScoreNew();
	
	static int GetScore();
	static void SaveScore();
	static vector<int> ReadScore();
	static void Increment(int points);
	static void PowerupTaken();
	static void FoodEaten();	
	static int GetPowerupsTaken();
	static int GetFoodEaten();

private:
	static int score;
	static int powerupsTaken;
	static int foodEaten;
};	
