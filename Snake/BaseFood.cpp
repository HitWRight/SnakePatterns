#include <memory>
#include <random>
#include "Score.h"
#include "Wall.h"
#include "Singleton.h"
#include "BaseFood.h"
#include "Snake.h"
#include "Vec2d.h"
#include "Powerup.h"


using namespace std;

//random_device rd;
//mt19937 gen(rd());
//uniform_real_distribution<> dis(MIN, MAX);

void BaseFood::Spawn()
{
	//Vec2d nextPos = 
	//}();
	//m_position.push_back(nextPos);
}
void BaseFood::DrawAll()
{
	for (auto a : m_position)
		ConsoleDraw::GetConsole().Draw(a, sym);
}

void BaseFood::FixedUpdate()
{
	Vec2d pos = Singleton<Snake>::Instance().GetHeadPosition();
	for (auto vb = m_position.begin(), ve = m_position.end(); vb != ve; ++vb)
	{
		if (vb->x == pos.x && vb->y == pos.y)
		{
			m_position.erase(vb);
			Eat();

			break;
		}
	}

}
