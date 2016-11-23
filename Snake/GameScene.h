#pragma once

#include <vector>
#include <random>
#include <memory>
#include <functional>

#include "Item.h"
#include "Singleton.h"
#include "State.h"
#include <Windows.h>

struct GameScene : State
{
	friend class Singleton<GameScene>;

	std::vector<Item*> mapItems;
	int m_counter;
	bool m_firstTime;

	std::function<void()> m_callback;

	GameScene();
	void GenerateEnemies(int difficulty);

	void Load();
	void Save();
public:

	void SetCallback(std::function<void()> returnToMenu);

	void Update();
	void RemoveItem(Item* item);
	Vec2d const& GetUnusedPosition();
	bool IsPositionTaken(Vec2d const& position);

};

struct Memento
{
	static PCHAR_INFO buffer;
};