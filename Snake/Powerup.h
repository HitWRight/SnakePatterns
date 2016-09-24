#pragma once
#include "BaseFood.h"
#include "Settings.h"
#include "PowerupTypes.h"
class Powerup : public BaseFood{
public:
	Powerup(PowerupTypes type);
	Powerup();
	int GetCount();
private:
	PowerupTypes type;


	// Inherited via BaseFood
	virtual void Eat() override;
};