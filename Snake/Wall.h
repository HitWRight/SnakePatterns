#pragma once
#include "Vec2d.h"
#include <cstdlib>
#include <vector>
#include "ConsoleDraw.h"
#include "Settings.h"
#include "Singleton.h"
#include <memory>



static class Wall
{
	friend class Singleton<Wall>;

private:
	std::vector<Vec2d> boundary;

public:
	bool CheckBoundary(Vec2d const&);
	void Generate(int,unsigned short int);
	void Draw();

protected:
	Wall();
	~Wall();

private:
	void GenerateWall(Vec2d from, Vec2d to);
	
	
};


