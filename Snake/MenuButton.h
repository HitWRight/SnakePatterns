#pragma once

namespace MenuNS {

	enum class MenuCommand
	{
		PlayGame,
		Exit
	};

	class MenuButton
	{
		MenuButton* next;

	public:
		MenuButton() : next(0) {  }
		void AddNext(MenuButton* next);
		void SetNext(MenuButton* next);

		virtual void HandleClick(MenuCommand menuCommand);
		
	};
}

