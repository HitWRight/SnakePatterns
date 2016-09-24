#include <iostream>
#include <Windows.h>
#include "Snake.h"
#include "ConsoleDraw.h"
#include "Food.h"
#include "Speed.h"
#include "Wall.h"
#include "Settings.h"
#include "Singleton.h"
#include "Powerup.h"

int main()
{
	//printf("%s%s", (true ? "test", "test2" : "test3", "test4"));

	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.X = 16;
	info.dwFontSize.Y = 12; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"CONSOLAS");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	MoveWindow(GetConsoleWindow(), posX, posY, windowX, windowY, TRUE);

	Food f(3);
	Powerup p(1, '^');
	Wall::Instance().Draw();
	

	while(true)
	{
				
		f.FixedUpdate();
		p.FixedUpdate();
		Singleton<Snake>::Instance().FixedUpdate();
		Sleep(Speed::Instance().GetSpeed());
	} 
	

	return 0;
}