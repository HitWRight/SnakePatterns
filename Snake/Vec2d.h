#pragma once


struct Vec2d
{
	short int x, y;

	Vec2d operator+(Vec2d const& other) const { return{ x + other.x, y + other.y }; }



	//bool operator==(Vec2d const& other) { return other.x == x && other.y == y; }
	bool operator==(Vec2d && other) { return other.x == x && other.y == y; }
	bool operator==(Vec2d const& other) const { return other.x == x && other.y == y; }

	
	//const bool operator==(Vec2d const other) { return other.x == x && other.y == y; }
};