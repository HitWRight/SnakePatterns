#include "GameScene.h"
#include "ItemFactory.h"
#include "FoodFactory.h"
#include "PowerupFactory.h"
#include "Snake.h"
#include "Wall.h"
#include "Enemy.h"

#include <algorithm>

#define COUNTER_SETTING 5
#define MIN 0
#define MAX 4

#define POWERUP 0

std::uniform_real_distribution<> dis(MIN, MAX);



GameScene::GameScene() : m_counter(0), m_firstTime(true)
{
	
}

void GameScene::GenerateEnemies(int difficulty)
{
	for (int i = 0; i < difficulty; i++)
	{
		mapItems.push_back(static_cast<Item*>(new EnemyNS::Enemy()));
	}
}

void GameScene::Update()
{
	if (m_firstTime)
	{
		GenerateEnemies(2);
		m_firstTime = false;
	}

	for (Item* i : mapItems)
	{
		if (i->Update()) break; //Expensive stuff, baby. *snort*
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	m_counter++;
	if (COUNTER_SETTING <= m_counter && mapItems.size() < 5)
	{
		ItemFactory* factory = [](int randNumber) {
			if (POWERUP == randNumber)
				return static_cast<ItemFactory*>(new PowerupFactory); // Fuck VC++ with inability to correctly deduce types inside lambdas
			return static_cast<ItemFactory*>(new FoodFactory);
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
		std::random_device rd;
		std::mt19937 gen(rd());
		Vec2d tryPos = { (short int)dist(gen), (short int)dist(gen) };
		if (!IsPositionTaken(tryPos))
			return tryPos;
	}
}

bool GameScene::IsPositionTaken(Vec2d const& position)
{
	bool taken = false;
	if (Singleton<Snake>::Instance().spaceTaken(position) || Singleton<Wall>::Instance().CheckBoundary(position))
		taken = true;

	for (auto item : mapItems)
	{
		if (item->GetPosition() == position)
			taken = true;
	}
	return taken;
}
