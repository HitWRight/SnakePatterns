#include "Food.h"
#include "Snake.h"
#include "ConsoleDraw.h"
#include "Speed.h"

#include <vector>
#include <memory>
#include <random>

#define MIN 1
#define MAX 24

#define FOODSYMBOL '*'

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(MIN, MAX);

Food::Food(int count)
{
	for (int n = 0; n < count; ++n) {
		m_position.push_back({(short int)dis(gen), (short int)dis(gen)});
	}

	DrawAll();
}

void Food::FixedUpdate()
{
	Vec2d pos = Snake::Instance().GetHeadPosition();
	for (auto vb = m_position.begin(), ve = m_position.end(); vb != ve; ++vb )
	{
		if (vb->x == pos.x && vb->y == pos.y)
		{
			m_position.erase(vb);
			EatSingle();
			
			break;
		}
	}

}

void Food::DrawAll()
{
	for (auto a : m_position)
		ConsoleDraw::Draw(a, FOODSYMBOL);
}

void Food::EatSingle()
{
	Snake::Instance().IncreaseSize(1);

	Vec2d nextPos = []() {
		while (true)
		{
			Vec2d tryPos = { (short int)dis(gen), (short int)dis(gen) };
			if (!Snake::Instance().spaceTaken(tryPos))
				return tryPos;
		}
	}();
	m_position.push_back({(short int)dis(gen), (short int)dis(gen)});
	
	ConsoleDraw::Draw(*(m_position.end()-1), FOODSYMBOL);
	Speed::Instance().IncreaseLevel();
}
