#pragma once
#include "Vec2d.h"
#include <vector>

using namespace std;

class BaseFood {
public:
	void FixedUpdate(vector<Vec2d> &position);
protected:
	void DrawAll(vector<Vec2d> &const position, char sym);
	virtual void Eat() = 0;
	void Spawn(vector<Vec2d> &position);
};
