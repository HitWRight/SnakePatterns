#pragma once
#include "Settings.h"
#include <vector>

static class Score {
private:
	static int score;
public:

	static void Increment(int points);
	static int GetScore();
	static void SaveScore();
	static std::vector<int> ReadScore();
};