#pragma once
#include "ItemFactory.h"
#include "Food.h"

struct FoodFactory : ItemFactory
{
	Item* CreateItem();
};