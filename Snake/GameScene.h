#pragma once

#include <vector>
#include <random>
#include <memory>

#include "Item.h"
#include "Singleton.h"

struct GameScene
{
	friend class Singleton<GameScene>;

	std::vector<Item*> mapItems;
	int m_counter;
	bool m_firstTime;

	GameScene();
	void GenerateEnemies(int difficulty);

public:
	
	void Update();
	void RemoveItem(Item* item);
	Vec2d const& GetUnusedPosition();
	bool IsPositionTaken(Vec2d const& position);

};