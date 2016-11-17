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
	switch (m_selection)
	{
	case 0:
		m_menu1callback();
		break;
	case 1:
		exit(1);
	default:
		break;
	}

}

Menu::Menu(std::function<void()> menu1callback)
{
	m_menu1callback = menu1callback;
	//menu1callback();
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
		ConsoleDraw::Erase(icoPos);
	}

	ConsoleDraw::Draw(c_icoPositions[m_selection], '*');
	//update graphics

}



void Menu::Load()
{
	ConsoleDraw::Draw({ 6, 5 }, "New game");
	ConsoleDraw::Draw({ 6, 7 }, "Exit");

	//TODO: load state from file

	m_selection = 0;

	ConsoleDraw::Draw(c_icoPositions[m_selection], '*');
}

void Menu::Save()
{
	//TODO: save state to file
}
