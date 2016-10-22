#pragma once

#include <vector>
#include <random>
#include <memory>

#include "Item.h"
#include "Singleton.h"


std::random_device rd;
std::mt19937 gen(rd());


struct GameScene
{
	friend class Singleton<GameScene>;

	std::vector<Item*> mapItems;
	int m_counter;

	GameScene();

public:
	
	void Update();
	void RemoveItem(Item* item);
	Vec2d const& GetUnusedPosition();
	
};