#include "ActivateServant.h"



ActivateServant::ActivateServant()
{
}


ActivateServant::~ActivateServant()
{
}

void ActivateServant::Activate(Activatable& activate) {
	activate.Activate();
}