#pragma once
#include "Item.h"
#include "EnemyCommand.h"
#include <queue>

namespace EnemyNS
{
	struct Enemy;
	enum class MovementDirection;

	typedef void(Enemy::* enemyMethod)(MovementDirection);

	struct EnemyCommand
	{
	private:
		Enemy* m_enemy;
		MovementDirection m_direction;
		enemyMethod m_method;


	public:
		EnemyCommand(EnemyNS::Enemy* enemy, enemyMethod method, MovementDirection direction);

		void Execute();
	};

	enum class MovementDirection
	{
		none = 0,
		left,
		right,
		up,
		down
	};

	struct Enemy : Item
	{
	private:
		std::queue<EnemyCommand> cmdQ;

	public:
		Enemy();

		bool Update();
		void Move(MovementDirection direction);


	};
}
