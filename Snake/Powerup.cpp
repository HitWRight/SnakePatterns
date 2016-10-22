#include "Powerup.h"
#include "Speed.h"
#include "Snake.h"
#include "Singleton.h"
#include "GameScene.h"
#include "ConsoleDraw.h"
#include <random>

std::uniform_real_distribution<> dis(0, 2);

Powerup::Powerup()
{
	m_position = Singleton<GameScene>::Instance().GetUnusedPosition();

	m_type = static_cast<PowerupTypes>((short int)dis(gen));

	switch (m_type)
	{
	case PowerupTypes::Speed:
		for(int i=0;i<5;i++)
		Singleton<Speed>::Instance().IncreaseLevel();
		break;
	case PowerupTypes::Size:
		Singleton<Snake>::Instance().IncreaseSize(5);
		break;
	case PowerupTypes::Reverse:
		Singleton<Snake>::Instance().Reverse();
		break;
	default:
		throw new std::exception("Something fucky was with the Powerups");
	}

	ConsoleDraw::Draw(m_position, '+');
}

bool Powerup::Update()
{
	return false;
}
