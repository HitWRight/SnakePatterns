#pragma once

#include <Windows.h>
#include <iostream>
#include "Vec2d.h"
#include <string>
namespace ConsoleDraw {
	
	struct Console
	{
	private:
		int m_width, m_height;


	public:

		Console(int height, int width);

		void Draw(Vec2d const& pos, char const& symbol);

		void Draw(std::string const& text);

		void Draw(Vec2d const& pos, std::string const& text);

		void Erase(Vec2d const& pos);

		void ClearConsole();

		std::string ReadBuffer();

		void WriteBuffer(std::string data);
	};

	using std::cout;

	static Console& GetConsole()
	{
		static Console instance(25,25);
		return instance;
	}

	
}