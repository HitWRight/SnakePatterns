#pragma once
#include "Vec2d.h"
#include <memory>
#include <vector>
#include "BaseFood.h"

class Food : BaseFood
{
private:

	void DrawAll();
	std::vector<Vec2d> m_position;

	// Inherited via BaseFood
	virtual void Eat() override;

public:
	Food(int count);
	void FixedUpdate();

};
