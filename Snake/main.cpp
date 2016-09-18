#include <iostream>
#include <Windows.h>
#include "Snake.h"
#include "ConsoleDraw.h"
#include "Food.h"
#include "Speed.h"
#include "Wall.h"
#include "Settings.h"

int main()
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.X = 16;
	info.dwFontSize.Y = 12; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"CONSOLAS");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	MoveWindow(GetConsoleWindow(), posX, posY, windowX, windowY, TRUE);


	/*for (short int i = 0; i < 25; i++)
	{
		ConsoleDraw::Draw(Vec2d{ i, (short)0 }, '#');
		ConsoleDraw::Draw(Vec2d{ i, (short)24 }, '#');
		ConsoleDraw::Draw(Vec2d{ (short)0, i }, '#');
		ConsoleDraw::Draw(Vec2d{ (short)24, i }, '#');
	}*/


	Wall::Instance().Draw();
	Food f(3);

	while(true)
	{
				
		f.FixedUpdate();
		Snake::Instance().FixedUpdate();
		Sleep(Speed::Instance().GetSpeed());
	} 
	

	return 0;
}