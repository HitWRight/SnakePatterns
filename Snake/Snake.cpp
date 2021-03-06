#include "Snake.h"
#include "ConsoleDraw.h"
#include "Death.h"
#include <Windows.h>
#include "Wall.h"
#include "MoveClient.h"

#define BODYSYMBOL 'O'

using namespace std;

//first element head, last element tail

Snake::Snake() : m_clearPos({0,0}), 
				m_body(0), 
				m_curMoveDir(Direction::none)
{
	m_body.push_back(Vec2d{ 12, 12 });
	m_body.push_back(Vec2d{ 12, 12 });
	m_body.push_back(Vec2d{ 12, 12 });

	
}

void Snake::Move()
{
	m_clearPos =  m_body.back();

	MoveClient client;
	Up up;
	Down down;
	Left left;
	Right right;
	None none;

	switch (m_curMoveDir)
	{
		case Direction::down:
			client.SetStrategy(&down);
			break;
		case Direction::up:
			client.SetStrategy(&up);
			break;
		case Direction::left:
			client.SetStrategy(&left);
			break;
		case Direction::right:
			client.SetStrategy(&right);
			break;
		case Direction::none:
			client.SetStrategy(&none);
			break;

	}

	Vec2d nextPos = client.Move(m_body[0]);/*[&](Direction moveDir , Vec2d headPos)
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
	}(m_curMoveDir, m_body[0]);*/
	
//	for (auto ve = end(m_body), vb = begin(m_body) + 1; vb != ve; --ve)
//		ve = (ve - 1);

	for (int i = m_body.size() - 1; i > 0; --i)
		m_body[i] = m_body[i - 1];

	m_body[0] = nextPos;

}

void Snake::Redraw()
	{
	ConsoleDraw::GetConsole().Draw(m_clearPos, ' ');

	for (Vec2d coords : m_body)
		ConsoleDraw::GetConsole().Draw(coords, BODYSYMBOL);
}

void Snake::CheckCollisionWithSelf()
{
	if (m_curMoveDir == Direction::none)
		return;
	for(auto vi=m_body.begin() + 1; vi != m_body.end(); ++vi)
		if (m_body[0] == *vi)
		{
			Death::Die();
		}
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
	Move();
	Redraw();
	CheckCollisionWithSelf();
	if (Singleton<Wall>::Instance().CheckBoundary(m_body[0])) {
		Death::Die();
	};
}

void Snake::Reverse()
{
	reverse(m_body.begin(), m_body.end());
	
	//Set Direction to tail
	if (m_body.size() < 2)
		throw new std::exception("Snake too short for reverse too work correctly, reimplement the function for correct behaviour");

	m_curMoveDir = [&]() { 
		if (m_body[0].x > m_body[1].x)
			return Direction::right;
		if (m_body[0].x < m_body[1].x)
			return Direction::left;
		if (m_body[0].y > m_body[1].y)
			return Direction::down;

		return Direction::up;
	}();
}

void Snake::IncreaseSize(int addition)
{
	for (int i = 0; i < addition; ++i)
	{
		m_body.push_back({ m_body[0].x, m_body[0].y });
	}
}
