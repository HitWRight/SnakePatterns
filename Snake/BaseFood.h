#pragma once
#include "Vec2d.h"
#include <vector>

using namespace std;

class BaseFood {
public:
	virtual void FixedUpdate();
	void Spawn();
protected:
	std::vector<Vec2d> m_position;
	char sym;


	void DrawAll();
	virtual void Eat() = 0;
	
};
