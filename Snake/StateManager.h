#pragma once

#include "State.h"
#include "Menu.h"
#include "GameScene.h"
#include "Singleton.h"

struct StateManager
{
private:
	friend struct Singleton<StateManager>;

	State* m_currentState;

	StateManager();
	void ChangeToGameScene();
	void ChangeToMenu();

public:
	void Update();
};