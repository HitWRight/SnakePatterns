#include "Food.h"
#include "Snake.h"
#include "GameScene.h"
#include "Singleton.h"
#include "ConsoleDraw.h"
#include "Speed.h"
#include "Score.h"

//Food::Food(Vec2d const & initPos) : Item(initPos)
//{
//
//}

Food::Food() : Item()
{
	m_position = Singleton<GameScene>::Instance().GetUnusedPosition();
	ConsoleDraw::GetConsole().Draw(m_position, '*');
}


bool Food::Update()
{
	if (Singleton<Snake>::Instance().GetHeadPosition() == m_position)
	{
		Singleton<GameScene>::Instance().RemoveItem(this);
		Singleton<Snake>::Instance().IncreaseSize(1);
		Singleton<Speed>::Instance().IncreaseLevel();
		Score::FoodEaten();
		return true;
	}
	return false;
}
