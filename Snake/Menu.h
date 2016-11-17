#pragma once
#include <functional>
#include <vector>

#include "State.h"
#include "ConsoleDraw.h"

struct Menu : State
{
private:
	const std::vector<Vec2d> c_icoPositions = { { 5, 5 } , { 5, 7 } };
	int m_selection;

	std::function<void()> m_menu1callback;

	void HandleSpace();



public:
	Menu(std::function<void()> menu1callback);

	void Update();
	void Load();
	void Save();
};