#include "Enemy.h"
#include "ConsoleDraw.h"
#include "Singleton.h"
#include "GameScene.h"
#include "Snake.h"
#include "Death.h"

using namespace EnemyNS;

Enemy::Enemy() : Item()
{
	m_position = Singleton<GameScene>::Instance().GetUnusedPosition();
	ConsoleDraw::Draw(m_position, 'Y');
}

bool Enemy::Update()
{
	if (Singleton<Snake>::Instance().GetHeadPosition() == m_position)
		Death::Die();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 5);
	int wut = (short int)dis(gen);
	cmdQ.push(EnemyCommand(this, &Enemy::Move, static_cast<MovementDirection>(wut)));

	if (cmdQ.size() > 10)
	{
		cmdQ.front().Execute();
		cmdQ.pop();
	}

	return false;
}

void Enemy::Move(MovementDirection direction)
{
	Vec2d nextPos = [](Vec2d const& curPos,  MovementDirection const& dir)
	{
		switch (dir)
		{
		case MovementDirection::up:
			return curPos + Vec2d{ 0, -1 };
		case MovementDirection::down:
			return curPos + Vec2d{ 0, 1 };
		case MovementDirection::left:
			return curPos + Vec2d{ -1, 0 };
		case MovementDirection::right:
			return curPos + Vec2d{ 1, 0 };
		default:
			return curPos;
		}
	}(m_position, direction);

	if (!Singleton<GameScene>::Instance().IsPositionTaken(nextPos))
	{
		ConsoleDraw::Draw(nextPos, 'H');
		ConsoleDraw::Erase(m_position);
		m_position = nextPos;
	}
}
