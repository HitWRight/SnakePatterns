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
#include "GameScene.h"
//#include <ctime>

#include <chrono>
#include <thread>


int main()
{

	srand(time(NULL));

	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.X = 16;
	info.dwFontSize.Y = 12; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"CONSOLAS");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	MoveWindow(GetConsoleWindow(), posX, posY, windowX, windowY, TRUE);

	Singleton<Wall>::Instance().Draw();

	while(true)
	{
		Sleep(Singleton<Speed>::Instance().GetSpeed());

		Singleton<GameScene>::Instance().Update();
		Singleton<Snake>::Instance().FixedUpdate();

		std::this_thread::sleep_until(
			std::chrono::high_resolution_clock::now() + 
			static_cast<std::chrono::milliseconds>(
				Singleton<Speed>::Instance().GetSpeed()));
	} 
	

	return 0;
}