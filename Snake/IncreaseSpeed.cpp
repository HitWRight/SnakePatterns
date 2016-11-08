#include "IncreaseSpeed.h"
#include "Singleton.h"
#include "Speed.h"
#define TIMES 5

IncreaseSpeed::IncreaseSpeed()
{
}


IncreaseSpeed::~IncreaseSpeed()
{
}

void IncreaseSpeed::Activate() {

	for (int i = 0; i < TIMES; i++)
		Singleton<Speed>::Instance().IncreaseLevel();
}