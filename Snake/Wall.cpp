#include "Wall.h"
#include <cmath>
#include <ctime>
#include "Snake.h"
#include "Singleton.h"


using namespace std;

bool Wall::CheckBoundary(Vec2d const& target) {
	for(auto& a : boundary)
	{
		if (target == a)
			return true;
	}
	return false;
}


void Wall::Generate(int size = DEFAULT_SIZE, unsigned short int difficulty = DEFAULT_DIFFICULTY) {
	switch (difficulty)
	{
	case 0:
		box:
		for (short int i = 0; i < size; i++)
		{
			boundary.push_back(Vec2d{ i, (short)0 });
			boundary.push_back(Vec2d{ i, (short)size - 1 });
			boundary.push_back(Vec2d{ (short)0, i });
			boundary.push_back(Vec2d{ (short)size - 1, i });
		}
		break;
	default:

		srand(time(NULL));
		for (int i = 0; i < difficulty; i++) {
			int randomX = rand() % (size - 2) + 1; //1-24
			int randomY = rand() % (size - 2) + 1; //1-24
			bool direction = (rand() % 2 == 0);
			int randomLength = [&](int randX, int randY) {	
				int len = rand() % size + 3; //3-27
				if (direction)
					return (len + randomX >= size) ? (size - randomX - 1) : len; //24-3
				return (len + randomY >= size) ? (size - randomY - 1) : len;
			}(randomX, randomY);
			
			

			//GenerateWall({ 10,10 }, { 10,0 });

			if (direction) {
				GenerateWall(Vec2d{(short) randomX,(short)randomY }, Vec2d{ (short)(randomX + randomLength), (short)randomY});
			}
			else {

				GenerateWall(Vec2d{ (short)randomX, (short)randomY }, Vec2d{ (short)randomX , (short)(randomY + randomLength) });
			}

		}
		goto box;
	}
}

void Wall::GenerateWall(Vec2d from, Vec2d to) {
	if (from.x != to.x && from.y != to.y) {
		throw std::exception("Bad coordinates. Can't make wall!");
		return;
	}

	if (from.x >= to.x && from.y >= to.y)
		swap(from, to);


	while (from.x != to.x || from.y != to.y) {
		if (from.x < to.x) {
			from.x++;
		}
		if (from.y < to.y) {
			from.y++;
		}

		if (!CheckBoundary(from) && !(Singleton<Snake>::Instance().GetHeadPosition() == from))
			boundary.push_back(from);
	}
}

void Wall::Draw() {
	for(auto b : boundary)
		ConsoleDraw::Draw(b, DEFFAULT_SYMBOL_WALL);
}

Wall::Wall() {
	Generate(DEFAULT_SIZE, DEFAULT_DIFFICULTY);
}

Wall::~Wall()
{
}
