#pragma once
#include "Item.h"
#include "PowerupTypes.h"


class Powerup : public Item{
public:
	Powerup();
private:
	PowerupTypes m_type;
	bool Update();
};