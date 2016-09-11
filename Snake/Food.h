#pragma once
#include "Vec2d.h"
#include <memory>
#include <vector>

class Food
{
private:
	std::vector<Vec2d> m_position;

	void DrawAll();

	void EatSingle();
public:
	Food(int count);
	void FixedUpdate();
};
