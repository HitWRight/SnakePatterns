#include <iostream>
#include <Windows.h>
#include "ConsoleDraw.h"
#include "Food.h"
#include "Speed.h"
#include "Wall.h"
#include "Settings.h"
#include "Singleton.h"
#include "Powerup.h"
#include "StateManager.h"
//#include <ctime>

#include <chrono>
#include <thread>


int main()
{

	srand(time(NULL));

	while(true)
	{
		Singleton<StateManager>::Instance().Update();
	
		std::this_thread::sleep_until(
			std::chrono::high_resolution_clock::now() + 
			static_cast<std::chrono::milliseconds>(
				Singleton<Speed>::Instance().GetSpeed()));
	} 
	

	return 0;
}