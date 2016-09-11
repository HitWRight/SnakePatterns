#pragma once

#include <Windows.h>
#include <iostream>
#include "Vec2d.h"

namespace ConsoleDraw {
	

	using std::cout;

	static void Draw(const Vec2d pos, const char symbol)
	{
		//Initialize the coordinates
		COORD coord = { pos.x, pos.y }; //Static cast unable to work
		//Set the position
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << symbol;
		
		return;
	}

	static void Erase(const Vec2d pos)
	{
		Draw(pos, 'X');
	}

	static void ClearConsole()
	{
		for (short int i = 0; i < 25; ++i)
			for (short int j = 0; j < 25; ++j)
				Draw({ i,j }, ' ');
	}
}