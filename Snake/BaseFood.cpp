#include <memory>
#include <random>
#include "Score.h"
#include "Wall.h"
#include "Singleton.h"
#include "BaseFood.h"
#include "Snake.h"
#include "Vec2d.h"


using namespace std;

#define MIN 1
#define MAX 24


random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(MIN, MAX);

void BaseFood::Spawn(vector<Vec2d> &position)
{
	Vec2d nextPos = []() {
		while (true)
		{
			Vec2d tryPos = { (short int)dis(gen), (short int)dis(gen) };
			if (!Singleton<Snake>::Instance().spaceTaken(tryPos) && !Wall::Instance().CheckBoundary(tryPos))
				return tryPos;
		}
	}();
	position.push_back(nextPos);
}
void BaseFood::DrawAll(vector<Vec2d> &const position, char sym)
{
	for (auto a : position)
		ConsoleDraw::Draw(a, sym);
}

void BaseFood::FixedUpdate(vector<Vec2d> &position)
{
	Vec2d pos = Singleton<Snake>::Instance().GetHeadPosition();
	for (auto vb = position.begin(), ve = position.end(); vb != ve; ++vb)
	{
		if (vb->x == pos.x && vb->y == pos.y)
		{
			position.erase(vb);
			Eat();

			break;
		}
	}

}