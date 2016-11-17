#pragma once

#include <Windows.h>
#include <iostream>
#include "Vec2d.h"
#include <string>
namespace ConsoleDraw {
	

	using std::cout;

	static void Draw(Vec2d const& pos, char const& symbol)
	{
		//Initialize the coordinates
		COORD coord = { pos.x, pos.y }; //Static cast unable to work
		//Set the position
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << symbol;
		
		return;
	}


	static void Draw(std::string const& text)
	{
		cout << text;
		return;
	}


	static void Draw(Vec2d const& pos, std::string const& text)
	{
		COORD coord = { pos.x,pos.y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		Draw(text);
	}

	static void Erase(Vec2d const& pos)
	{
		Draw(pos, ' ');
	}

	static void ClearConsole()
	{
		for (short int i = 0; i < 25; ++i)
			for (short int j = 0; j < 25; ++j)
				Draw({ i,j }, ' ');
	}
}