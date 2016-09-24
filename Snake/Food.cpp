#include "Food.h"
#include "Snake.h"
#include "ConsoleDraw.h"
#include "Speed.h"

#include <vector>
#include <memory>
#include <random>
#include "Score.h"
#include "Wall.h"
#include "Singleton.h"
#include "Settings.h"


Food::Food(int count)
{
	for (int n = 0; n < count; ++n) {
		BaseFood::Spawn(m_position);
	}

	DrawAll();
}

void Food::FixedUpdate()
{
	BaseFood::FixedUpdate(m_position);

}

void Food::Eat()
{
	Singleton<Snake>::Instance().IncreaseSize(1);
	Score::Increment(1);
	BaseFood::Spawn(m_position);
	ConsoleDraw::Draw(*(m_position.end() - 1), DEFFAULT_SYMBOL_FOOD);
	Speed::Instance().IncreaseLevel();
}

void Food::DrawAll()
{
	BaseFood::DrawAll(m_position, DEFFAULT_SYMBOL_FOOD);
}

