#pragma once
#include "ItemFactory.h"
#include "Food.h"
#include <functional>

struct FoodFactory : ItemFactory
{
	Item* CreateItem();
};