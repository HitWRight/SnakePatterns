#pragma once
#include "Powerup.h"

class PowerupHandler
{
private:
	int powerupCounter;
public:
	Powerup p;
	void Handle();
	PowerupHandler();
};

