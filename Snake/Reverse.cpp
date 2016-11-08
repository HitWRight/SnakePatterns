#include "Reverse.h"
#include "Singleton.h"
#include "Snake.h"


Reverse::Reverse()
{
}


Reverse::~Reverse()
{
}

void Reverse::Activate() {
	Singleton<Snake>::Instance().Reverse();
}