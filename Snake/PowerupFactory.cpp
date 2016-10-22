#include "PowerupFactory.h"
#include "Powerup.h"

Item * PowerupFactory::CreateItem()
{
	return new Powerup;
}
