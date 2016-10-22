#pragma once
#include "Item.h"
#include "ItemFactory.h"

struct PowerupFactory : ItemFactory
{
	Item* CreateItem();
};