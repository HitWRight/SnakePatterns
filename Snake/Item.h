#pragma once
#include "Vec2d.h"

struct Item
{
protected:
	Vec2d m_position;
public:
	Item();
	Item(Vec2d const& initialPosition);
	virtual bool Update() = 0;

	Vec2d const& GetPosition() { return m_position; }

	bool operator== (Item const& val) const { return m_position == val.m_position; }
};