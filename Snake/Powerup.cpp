#include "Powerup.h"
#include "Speed.h"
#include "Snake.h"
#include "Singleton.h"
#include "GameScene.h"
#include "ConsoleDraw.h"
#include <random>



Powerup::Powerup()
{
	m_position = Singleton<GameScene>::Instance().GetUnusedPosition();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 2);
	int wut = (short int)dis(gen);
	m_type = static_cast<PowerupTypes>(wut);

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

	ConsoleDraw::Draw(m_position, '&');
}

bool Powerup::Update()
{
	return false;
}
