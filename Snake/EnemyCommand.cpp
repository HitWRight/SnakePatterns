#include "EnemyCommand.h"

EnemyNS::EnemyCommand::EnemyCommand(Enemy* enemy, enemyMethod method, MovementDirection direction) : m_direction(direction), m_enemy(enemy), m_method(method)
{
}

void EnemyNS::EnemyCommand::Execute()
{
	(m_enemy->*m_method)(m_direction);
}
