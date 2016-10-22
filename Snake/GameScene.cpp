#include "GameScene.h"
#include "ItemFactory.h"
#include "FoodFactory.h"
#include "PowerupFactory.h"
#include "Snake.h"
#include "Wall.h"

#include <algorithm>

#define COUNTER_SETTING 5
#define MIN 0
#define MAX 4

#define POWERUP 0

std::uniform_real_distribution<> dis(MIN, MAX);

GameScene::GameScene() : m_counter(0)
{
}

void GameScene::Update()
{
	for (Item* i : mapItems)
	{
		if (i->Update()) break; //Expensive stuff baby *snort*
	}

	m_counter++;
	if (COUNTER_SETTING == m_counter)
	{
		ItemFactory* factory = [](int randNumber) {
			if (POWERUP == randNumber)
				return new PowerupFactory;
			return new FoodFactory;
		}(dis(gen));

		mapItems.push_back(factory->CreateItem());

		m_counter = 0;
	}
}

void GameScene::RemoveItem(Item* item)
{
	mapItems.erase( 
		std::remove_if(
			mapItems.begin(),
			mapItems.end(),
		[&](Item* elem) -> bool {
			if (*elem == *item)
				return true;
			else
				return false;
		}));
}

Vec2d const & GameScene::GetUnusedPosition()
{
	std::uniform_real_distribution<> dist(1, 24);
	while (true)
	{	
		Vec2d tryPos = { (short int)dist(gen), (short int)dist(gen) };
		if (!Singleton<Snake>::Instance().spaceTaken(tryPos) && !Singleton<Wall>::Instance().CheckBoundary(tryPos))
			return tryPos;
	}
}
