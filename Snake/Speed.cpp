#include "Speed.h"



Speed::Speed() : m_speed(500)
{
}

Speed::~Speed()
{
}

int Speed::GetSpeed()
{
	return m_speed;
}

void Speed::IncreaseLevel()
{
	m_speed -= (m_speed > 250) ? 10 : (m_speed > 50) ? 5 : 0;
}
