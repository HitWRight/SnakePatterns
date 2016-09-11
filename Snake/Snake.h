#pragma once
#include <vector>
#include <memory>

#include "Vec2d.h"
#include "Direction.h"

static class Snake
{
private:
	std::vector<Vec2d> m_body;
	Vec2d m_clearPos;
	Direction m_lastMoveDir;
	Direction m_curMoveDir;

	void Move();
	void Redraw();
	void CheckCollisionWithSelf();


	Snake(Snake&&) = delete; 
	Snake(Snake const&) = delete; 
	Snake& operator= (Snake const&) = delete; 
	Snake& operator= (Snake&&) = delete;



protected:
	Snake();
	~Snake();
public:
	

	static Snake& Instance()
	{
		static Snake instance;
		return instance;
	}

	void IncreaseSize(const int addition);
	void FixedUpdate();
	Vec2d GetHeadPosition() { return m_body[0]; }
	bool spaceTaken(Vec2d ch) { return (std::find(m_body.begin(), m_body.end(), ch)) == m_body.end() ? false : true; }
};

