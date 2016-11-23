#pragma once
#include "Activatable.h"
class NullPowerup :
	public Activatable
{
public:
	void Activate() override;
	NullPowerup();
	~NullPowerup();
};

