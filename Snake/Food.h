#pragma once
#include "Item.h"
#include "Vec2d.h"

class Food : public Item
{
private:

public:
	Food();
	//Food(Vec2d const& initPos);

	bool Update();
};
