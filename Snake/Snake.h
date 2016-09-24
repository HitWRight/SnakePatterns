#pragma once
#include <vector>
#include <memory>

#include "Vec2d.h"
#include "Direction.h"
#include "Singleton.h"

#define SINGLETONCLASS(classname) static class classname { friend class Singleton<classname>

//SINGLETONCLASS(Snake)

class Snake
{
	friend class Singleton<Snake>;

private:
	std::vector<Vec2d> m_body;
	Vec2d m_clearPos;
	Direction m_curMoveDir;
	void Move();
	void Redraw();
	void CheckCollisionWithSelf();

protected:
	Snake();
	
	~Snake();

public:
	void IncreaseSize(const int addition);
	void FixedUpdate();
	Vec2d GetHeadPosition() { return m_body[0]; }
	bool spaceTaken(Vec2d ch) { return (std::find(m_body.begin(), m_body.end(), ch)) == m_body.end() ? false : true; }
};

