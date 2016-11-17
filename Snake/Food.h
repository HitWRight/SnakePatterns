#pragma once
#include "Item.h"
#include "Vec2d.h"

#include <functional>

class Food : public Item
{
public:
	Food();

	bool Update();
};
