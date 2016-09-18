#include "Wall.h"
#include <cmath>


using namespace std;

bool Wall::CheckBoundary(Vec2d &target) {
	for (int i = 0; i < size; i++) {
		if (boundary[i] == target)
			return true;
	}

	return false;
}

void Wall::Generate(int size) {
	Wall::size = size;
	for (int i = 0; i < size; i++) {
		double randX = rand() % (int)size,  randY = rand() % (int)size;
		boundary.push_back({ (short int)randX, (short int)randY });
	}
}

void Wall::Generate(int x, int y) {
	Wall::size = size;
	for (int i = 0; i < size; i++) {
		double randX = rand() % (int)size, randY = rand() % (int)size;
		boundary.push_back({ (short int)randX, (short int)randY });
	}
}

void Wall::Generate() {
	int tempSize = 0;
	for (short int i = 0; i < 25; i++)
	{
		boundary.push_back(Vec2d{ i, (short)0 });
		boundary.push_back(Vec2d{ i, (short)24 });
		boundary.push_back(Vec2d{ (short)0, i });
		boundary.push_back(Vec2d{ (short)24, i });
		tempSize += 4;
	}
	Wall::size = tempSize;
	
}

void Wall::Draw() {
	for (int i = 0; i < size; i++) {
		ConsoleDraw::Draw(boundary[i], '+');
	}
}

Wall::Wall() {
	Generate();
	//Generate(200);
}

Wall::~Wall()
{
}
