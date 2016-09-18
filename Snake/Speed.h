#pragma once

class Speed
{
private:
	int m_speed;

	Speed(Speed&&) = delete;
	Speed(Speed const&) = delete;
	Speed& operator= (Speed const&) = delete;
	Speed& operator= (Speed&&) = delete;

protected:
	Speed();
	~Speed();

public:
	static Speed& Instance()
	{
		static Speed instance;
		return instance;
	}

	int GetSpeed();
	void IncreaseLevel();
};