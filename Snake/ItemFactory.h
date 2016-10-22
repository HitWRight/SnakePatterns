#pragma once

#include "Item.h"


struct ItemFactory{
	virtual Item* CreateItem() = 0;
};