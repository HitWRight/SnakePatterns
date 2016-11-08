#pragma once
#include "Activatable.h"
static class ActivateServant
{
public:
	ActivateServant();
	~ActivateServant();
	
	void Activate(Activatable& activate);
};

