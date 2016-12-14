#pragma once
#include <vector>
class ScoreBase {
	virtual int GetScore()=0;
	virtual void SaveScore()=0;
	virtual std::vector<int> ReadScore()=0;
};