#include "PlayButton.h"

void MenuNS::PlayButton::SetToPlay()
{
	m_callback();
}

MenuNS::PlayButton::PlayButton(std::function<void()> playCallback)
{
	m_callback = playCallback;
}

void MenuNS::PlayButton::HandleClick(MenuCommand menuCommand)
{
	if (MenuCommand::PlayGame == menuCommand)
		SetToPlay();
	else
		MenuButton::HandleClick(menuCommand);
}
