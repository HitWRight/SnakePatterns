#include "StateManager.h"

StateManager::StateManager()
{
	m_currentState = static_cast<State*>(new Menu([&]() {ChangeToGameScene(); }));
	m_currentState->Load();
	Singleton<GameScene>::Instance().SetCallback([&]() {ChangeToMenu(); });
}

void StateManager::ChangeToGameScene()
{
	m_currentState->Save();
	m_currentState = static_cast<State*>(&Singleton<GameScene>::Instance());
	m_currentState->Load();
}

void StateManager::ChangeToMenu()
{
	m_currentState->Save();
	m_currentState = static_cast<State*>(new Menu([&]() {ChangeToGameScene(); }));
	m_currentState->Load();
}

void StateManager::Update()
{
	m_currentState->Update();
}
