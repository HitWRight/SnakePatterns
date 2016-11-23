#include "Powerup.h"
#include "Speed.h"
#include "Snake.h"
#include "Singleton.h"
#include "GameScene.h"
#include "ConsoleDraw.h"
#include "ActivateServant.h"
#include "IncreaseSpeed.h"
#include "IncreaseSize.h"
#include "Reverse.h"
#include "NullPowerup.h"
#include "Score.h"
#include <random>



Powerup::Powerup()
{
	m_position = Singleton<GameScene>::Instance().GetUnusedPosition();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 2);
	int wut = (short int)dis(gen);
	m_type = static_cast<PowerupTypes>(wut);

	

	ConsoleDraw::Draw(m_position, '&');
}

bool Powerup::Update()
{
	if (m_position == Singleton<Snake>::Instance().GetHeadPosition())
	{
		ActivateServant servant;
		NullPowerup null;
		Activatable* activate = &null;
		IncreaseSpeed speed;
		IncreaseSize size;
		Reverse reverse;
		switch (m_type)
		{
		case PowerupTypes::Speed:
			activate = &speed;
			/*for (int i = 0; i < 5; i++)
				Singleton<Speed>::Instance().IncreaseLevel();*/
			break;
		case PowerupTypes::Size:
			activate = &size;
			//Singleton<Snake>::Instance().IncreaseSize(5);
			break;
		case PowerupTypes::Reverse:
			activate = &reverse;
			//Singleton<Snake>::Instance().Reverse();
			break;
		/*default:
			throw new std::exception("Something fucky was with the Powerups");*/
		}
		Score::PowerupTaken();
		servant.Activate(*activate);
		return true;
	}

	return false;
}
