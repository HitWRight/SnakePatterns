#pragma once
#include "Food.h"
#include "BaseFood.h"
#include "Settings.h"

class Powerup : BaseFood{
public:
	Powerup(int count, char sym);
	void DrawAll();
	void FixedUpdate();
private:
	//random buffs
	//random spawn
	int points;
	char sym;
	std::vector<Vec2d> m_position;
	


	// Inherited via IEatable
	virtual void Eat() override;
};