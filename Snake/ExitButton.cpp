#include "ExitButton.h"
#include <stdlib.h>

void MenuNS::ExitButton::ExitTheProgram()
{
	exit(0);
}

void MenuNS::ExitButton::HandleClick(MenuCommand menuCommand)
{
	if (menuCommand == MenuCommand::Exit)
		ExitTheProgram();
	else
		MenuButton::HandleClick(menuCommand);
}
