#pragma once

#include "IMoveable.h"
#include "Vec2d.h"
#include "Direction.h"

class MoveClient
{
public:
	void SetStrategy(IMoveable *strategy);
	Vec2d Move(Vec2d head) { return _strategyClient->Move(head); }
private:
	IMoveable *_strategyClient;
};

void MoveClient::SetStrategy(IMoveable *strategy) {
	_strategyClient = strategy;

}