#include "Score.h"
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

int Score::score;

void Score::Increment(int points) {
	Score::score += points;
}

int Score::GetScore() {
	return score;
}

void Score::SaveScore() {
	fstream output;
	output.open(FILE_SCORE, std::fstream::out | std::fstream::app);
	output << score << endl;
	output.close();
}

std::vector<int> Score::ReadScore() {
	static vector<int> scores;
	ifstream input;
	input.open(FILE_SCORE); //TODO check if file exists
	while (!input.eof()) {
		int tempscore;
		input >> tempscore;
		scores.push_back(tempscore);
	}

	return scores;
}