#include "Snake.h"
#include "ConsoleDraw.h"
#include <Windows.h>

#define BODYSYMBOL 'O'

using namespace std;

//first element head, last element tail

Snake::Snake() : m_clearPos({0,0}), 
				m_body(0), 
				m_curMoveDir(Direction::none), 
				m_lastMoveDir(Direction::none)
{
	m_body.push_back(Vec2d{ 12, 12 });
	m_body.push_back(Vec2d{ 12, 12 });
	m_body.push_back(Vec2d{ 12, 12 });
}

void Snake::Move()
{
	m_clearPos =  m_body.back();

	Vec2d nextPos = [&](Direction moveDir , Vec2d headPos)
	{
		switch (moveDir)
		{
		case Direction::down:
			return Vec2d{headPos.x, headPos.y + 1};
		case Direction::up:
			return Vec2d{ headPos.x, headPos.y - 1 };
		case Direction::left:
			return Vec2d{ headPos.x - 1, headPos.y };
		case Direction::right:
			return Vec2d{ headPos.x + 1, headPos.y };
		}

		return headPos;
	}(m_curMoveDir, m_body[0]);
	
//	for (auto ve = end(m_body), vb = begin(m_body) + 1; vb != ve; --ve)
//		ve = (ve - 1);

	for (int i = m_body.size() - 1; i > 0; --i)
		m_body[i] = m_body[i - 1];

	m_body[0] = nextPos;

}

void Snake::Redraw()
{
	ConsoleDraw::Draw(m_clearPos, ' ');

	for (Vec2d coords : m_body)
		ConsoleDraw::Draw(coords, BODYSYMBOL);
}

Snake::~Snake()
{
}

void Snake::FixedUpdate()
{
	Direction newDir = m_curMoveDir;
	
	//TODO: fix this shit probably to enumerate motion as bits
	SHORT keyPressedState = GetAsyncKeyState(VK_UP);
	if ((1 << 16) & keyPressedState && newDir != Direction::down)
		newDir = Direction::up;
	else
	{
		keyPressedState = GetAsyncKeyState(VK_DOWN);
		if ((1 << 16) & keyPressedState && newDir != Direction::up)
			newDir = Direction::down;
		else
		{
			keyPressedState = GetAsyncKeyState(VK_RIGHT);
			if ((1 << 16) & keyPressedState && newDir != Direction::left)
				newDir = Direction::right;
			else
			{


				keyPressedState = GetAsyncKeyState(VK_LEFT);
				if ((1 << 16) & keyPressedState && newDir != Direction::right)
					newDir = Direction::left;

			}
		}
	}
	
	m_curMoveDir = newDir;





	//get key
	//update movement direction
	//execute movement
	//redraw

	Move();

	Redraw();
}

void Snake::IncreaseSize(int addition)
{
	for (int i = 0; i < addition; ++i)
	{
		m_body.push_back({ m_body[0].x, m_body[0].y });
	}
}
