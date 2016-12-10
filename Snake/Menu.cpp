#pragma once
#include "Menu.h"
#include "ConsoleDraw.h"


enum class MenuDirection
{
	none,
	up,
	down
};

void Menu::HandleSpace()
{
     MenuNS::MenuCommand mc = [](int m_selection) {
		switch (m_selection)
		{
		case 0:
			return MenuNS::MenuCommand::PlayGame;
		case 1:
			return MenuNS::MenuCommand::Exit;
		}
		return MenuNS::MenuCommand::PlayGame;
	}(m_selection);

	m_FirstButton.HandleClick(mc);

}

Menu::Menu(std::function<void()> playCallback) : m_FirstButton(MenuNS::PlayButton(playCallback))
{
	//m_menu1callback = playCallback;
	//menu1callback();

	static MenuNS::ExitButton exitButton;
	m_FirstButton.AddNext(&exitButton);
}

void Menu::Update()
{
	MenuDirection mdir = MenuDirection::none;

	//listen to keys
	SHORT keyPressedState = GetAsyncKeyState(VK_UP);
	if ((1 << 16) & keyPressedState)
	{
		mdir = MenuDirection::up;
	}
	keyPressedState = GetAsyncKeyState(VK_DOWN);
	if ((1 << 16) & keyPressedState)
	{
		mdir = MenuDirection::down;
	}

	keyPressedState = GetAsyncKeyState(VK_SPACE);
	if ((1 << 16) & keyPressedState)
	{
		HandleSpace();
	}

	switch (mdir)
	{
	case MenuDirection::down:
		m_selection++;
		if (m_selection >= c_icoPositions.size()) m_selection = 0;
		break;
	case MenuDirection::up:
		m_selection--;
		if (m_selection < 0) m_selection = c_icoPositions.size() - 1;
		break;
	default:
		
		break;
	}

	for (auto icoPos : c_icoPositions)
	{
		ConsoleDraw::GetConsole().Erase(icoPos);
	}

	ConsoleDraw::GetConsole().Draw(c_icoPositions[m_selection], '*');
	//update graphics

}



void Menu::Load()
{
	ConsoleDraw::GetConsole().Draw({ 6, 5 }, "New game");
	ConsoleDraw::GetConsole().Draw({ 6, 7 }, "Exit");

	//TODO: load state from file

	m_selection = 0;

	ConsoleDraw::GetConsole().Draw(c_icoPositions[m_selection], '*');
}

void Menu::Save()
{
	//TODO: save state to file
}
