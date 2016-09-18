#include "Wall.h"
#include <cmath>


using namespace std;

bool Wall::CheckBoundary(Vec2d &target) {
	for (int i = 0; i < boundary.size(); i++) {
		if (boundary[i] == target)
			return true;
	}

	return false;
}

///__
///__|__|
///| |__ spanish inquisition
void Wall::Generate(int x, int y) {
	for (int i = 0; i < boundary.size(); i++) {
		double randX = rand() % (int)boundary.size(), randY = rand() % (int)boundary.size();
		boundary.push_back({ (short int)randX, (short int)randY });
	}
}

void Wall::Generate(int size = DEFAULT_SIZE) {
	for (short int i = 0; i < size; i++)
	{
		boundary.push_back(Vec2d{ i, (short)0 });
		boundary.push_back(Vec2d{ i, (short)size-1 });
		boundary.push_back(Vec2d{ (short)0, i });
		boundary.push_back(Vec2d{ (short)size-1, i });
	}
}

void Wall::Draw() {
	for (int i = 0; i < boundary.size(); i++) {
		ConsoleDraw::Draw(boundary[i], '+');
	}
}

Wall::Wall() {
	Generate();
}

Wall::~Wall()
{
}
