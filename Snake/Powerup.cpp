#include "Powerup.h"
#include "Snake.h"
#include "Score.h"
#include "Wall.h"
#include "Speed.h"
#include <random>
#include "PowerupTypes.h"



using namespace std;



void Powerup::Eat()
{
	Score::Increment((int)type);
	switch (type)
	{
	case PowerupTypes::Speed:
		for (int i = 0; i < POWER_UP_SPEED_INCREASE; i++)
			Speed::Instance().IncreaseLevel();
		break;
	case PowerupTypes::Size:
		Singleton<Snake>::Instance().IncreaseSize(POWER_UP_SIZE_INCREASE);
		break;
	case PowerupTypes::Reverse:
		Singleton<Snake>::Instance().Reverse();
		break;
	default:
		throw exception("Powerup not recognised!");
	}
	Singleton<Snake>::Instance().IncreaseSize(1);
	//ConsoleDraw::Draw(*(m_position.end() - 1), sym);
}


Powerup::Powerup(PowerupTypes type) 
{
	Powerup::type = type;
	switch (type)
	{
	case PowerupTypes::Speed:
		Powerup::sym = POWER_UP_SPEED;
		
		break;
	case PowerupTypes::Size:
		Powerup::sym = POWER_UP_SIZE;

		break;
	case PowerupTypes::Reverse:
		Powerup::sym = POWER_UP_REVERSE;

		break;
	default:
		Powerup::sym = DEFAULT_SYMBOL_POWERUP;
		break;
	}

	Powerup::Spawn();
	DrawAll();
}

Powerup::Powerup()
{
}

int Powerup::GetCount()
{
	return m_position.size();
}
