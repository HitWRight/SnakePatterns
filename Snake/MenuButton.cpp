#include "MenuButton.h"

void MenuNS::MenuButton::AddNext(MenuButton * next)
{
	if (this->next)
		this->next->AddNext(next);
	else
		SetNext(next);
}

void MenuNS::MenuButton::SetNext(MenuButton * next)
{
	this->next = next;
}

void MenuNS::MenuButton::HandleClick(MenuCommand menuCommand)
{
	if (next)
		next->HandleClick(menuCommand);
}
