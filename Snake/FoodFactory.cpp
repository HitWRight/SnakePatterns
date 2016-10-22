#include "FoodFactory.h"

Item * FoodFactory::CreateItem()
{
	return new Food;
}
