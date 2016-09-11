#include <iostream>
#include <Windows.h>
#include "Snake.h"
#include "ConsoleDraw.h"
#include "Food.h"

int main()
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.X = 16;
	info.dwFontSize.Y = 12; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"CONSOLAS");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	MoveWindow(GetConsoleWindow(), 200, 200, 460, 360, TRUE);

	for (short int i = 0; i < 25; i++)
	{
		ConsoleDraw::Draw(Vec2d{ i, (short)0 }, '#');
		ConsoleDraw::Draw(Vec2d{ i, (short)25 }, '#');
		ConsoleDraw::Draw(Vec2d{ (short)0, i }, '#');
		ConsoleDraw::Draw(Vec2d{ (short)25, i }, '#');
	}

	Food f(3);

	while(true)
	{
				
		f.FixedUpdate();
		Snake::Instance().FixedUpdate();
		Sleep(500);
	} 
	

	return 0;
}