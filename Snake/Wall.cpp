#include "Wall.h"
#include <cmath>
#include <ctime>
#include "Snake.h"


using namespace std;

bool Wall::CheckBoundary(Vec2d &target) {
	for (int i = 0; i < boundary.size(); i++) {
		if (boundary[i] == target)
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
			int randomX = rand() % (size - 2) + 1;
			int randomY = rand() % (size - 2) + 1;
			int random = rand();
			bool direction = (random % 2 == 0);
			int randomLength;
			if(direction)
				randomLength = rand() % (size - randomX) + 3;
			else 
				randomLength = rand() % (size - randomY) + 3;

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
		cout << "Bad coordinates. Can't make wall!\n";
		return;
	}


	while (from.x != to.x || from.y != to.y) {
		if (abs(from.x) < abs(to.x)) {
			from.x++;
		}
		if (abs(from.y) < abs(to.y)) {
			from.y++;
		}

		if (!CheckBoundary(from) && !(Snake::Instance().GetHeadPosition() == from))
			boundary.push_back(from);
	}
}

void Wall::Draw() {
	for (int i = 0; i < boundary.size(); i++) {
		ConsoleDraw::Draw(boundary[i], DEFFAULT_SYMBOL_WALL);
	}
}

Wall::Wall() {
	Generate(DEFAULT_SIZE, DEFAULT_DIFFICULTY);
}

Wall::~Wall()
{
}
