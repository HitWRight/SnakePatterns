#pragma once
#include "Vec2d.h"
#include <memory>
#include <vector>
#include "BaseFood.h"
#include "Settings.h"
#include "PowerupHandler.h"

class Food : public BaseFood
{
private:
	PowerupHandler handler;

	// Inherited via BaseFood
	virtual void Eat() override;

public:
	Food(int count = 0, char sym = DEFAULT_SYMBOL_FOOD);

	virtual void FixedUpdate() override;
};
