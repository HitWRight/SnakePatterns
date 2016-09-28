#pragma once
#include "Singleton.h"


class Speed
{
	friend class Singleton<Speed>;

private:
	int m_speed;

protected:
	Speed();
	~Speed();

public:
	int GetSpeed();
	void IncreaseLevel();
};