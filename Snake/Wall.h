#pragma once
#include "Vec2d.h"
#include <cstdlib>
#include <vector>
#include "ConsoleDraw.h"
#include "Settings.h"
#include <memory>



static class Wall
{
private:
	std::vector<Vec2d> boundary;

public:
	static Wall& Instance()
	{
		static Wall instance;
		return instance;
	}



	bool CheckBoundary(Vec2d&);
	void Generate(int);
	void Generate(int x, int y);

	void Draw();

protected:
	Wall();
	~Wall();

private:

	

	Wall(Wall&&) = delete;
	Wall(Wall const&) = delete;
	Wall& operator= (Wall const&) = delete;
	Wall& operator= (Wall&&) = delete;


	
	
};


