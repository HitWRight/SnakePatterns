#include "IncreaseSize.h"
#include "Singleton.h"
#include "Snake.h"
#define AMOUNT 5


IncreaseSize::IncreaseSize()
{
}


IncreaseSize::~IncreaseSize()
{
}

void IncreaseSize::Activate(){

	Singleton<Snake>::Instance().IncreaseSize(AMOUNT);
}