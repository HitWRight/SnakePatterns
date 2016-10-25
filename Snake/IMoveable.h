#pragma once
#include "Direction.h"
#include "Vec2d.h"


class IMoveable {
public:
	virtual Vec2d Move(Vec2d headPos) = 0;
};

class Up : public IMoveable {

public:
	Vec2d Move(Vec2d headPos) { return Vec2d{ headPos.x, headPos.y - 1 }; };
};

class Down : public IMoveable {

public:
	Vec2d Move (Vec2d headPos) { return Vec2d{ headPos.x, headPos.y + 1 }; };
};

class Left : public IMoveable {

public:
	Vec2d Move(Vec2d headPos) { return Vec2d{ headPos.x - 1, headPos.y }; };
};

class Right : public IMoveable {

public:
	Vec2d Move(Vec2d headPos) { return Vec2d{ headPos.x + 1, headPos.y }; };
};

class None : public IMoveable {

public:
	Vec2d Move(Vec2d headPos) { return headPos; };
};