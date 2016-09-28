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
#include "Powerup.h"


Food::Food(int count, char sym)
{
	handler = PowerupHandler();
	Food::sym = sym;
	for (int n = 0; n < count; ++n) {
		Food::Spawn();
	}

	DrawAll();
}

void Food::Eat()
{
	Singleton<Snake>::Instance().IncreaseSize(1);
	Score::Increment(1);
	Food::Spawn();
	handler.Handle();
	ConsoleDraw::Draw(*(m_position.end() - 1), sym);
	Singleton<Speed>::Instance().IncreaseLevel();
}

void Food::FixedUpdate() {
	BaseFood::FixedUpdate();
	handler.p.FixedUpdate();
}