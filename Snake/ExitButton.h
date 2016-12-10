#pragma once
#include "MenuButton.h"

namespace MenuNS
{
	class ExitButton : public MenuButton
	{
	private:
		void ExitTheProgram();
	public:
		virtual void HandleClick(MenuCommand menuCommand);
	};

}