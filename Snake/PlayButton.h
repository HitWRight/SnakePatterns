#pragma once
#include "MenuButton.h"
#include <functional>

namespace MenuNS
{
	class PlayButton : public MenuButton
	{
	private:
		std::function<void()> m_callback;

		void SetToPlay();
	public:
		PlayButton(std::function<void()> playCallback);

		virtual void HandleClick(MenuCommand menuCommand);
	};

}