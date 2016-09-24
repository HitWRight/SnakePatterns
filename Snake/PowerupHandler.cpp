#include "PowerupHandler.h"
#include <ctime>


PowerupHandler::PowerupHandler()
{
	powerupCounter = rand() % 5 + 3;;
}

void PowerupHandler::Handle() {
	powerupCounter--;
	if (powerupCounter <= 0) {
		int r = rand() % 2 + 4;
		p = Powerup((PowerupTypes) r);
		powerupCounter = rand() % 5 + 3;
	}
}
