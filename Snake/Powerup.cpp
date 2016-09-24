#include "Powerup.h"
#include "Snake.h"
#include "Score.h"
#include "Wall.h"
#include "Speed.h"
#include <random>
#include "PowerupTypes.h"


#define MIN 1
#define MAX 24


using namespace std;

void Powerup::Eat()
{
	//Singleton<Snake>::Instance().IncreaseSize(1);
	Score::Increment(points);
	BaseFood::Spawn(m_position);
	ConsoleDraw::Draw(*(m_position.end() - 1), sym);
	Speed::Instance().IncreaseLevel();
}



void Powerup::FixedUpdate()
{
	BaseFood::FixedUpdate(m_position);
}

Powerup::Powerup(int count = 0,  char sym = DEFFAULT_SYMBOL_POWERUP) {
	Powerup::sym = sym;
	for (int n = 0; n < count; ++n) {
		BaseFood::Spawn(m_position);
	}
	DrawAll();
}

void Powerup::DrawAll()
{
	BaseFood::DrawAll(m_position, sym);
}