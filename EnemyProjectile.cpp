#include "EnemyProjectile.h"
#include "GameManager.h"

EnemyProjectile::EnemyProjectile()
{
	SetTexture("Assets/Character/enemy_laser.png");
	SetSpeed(500);
	GameManager::m_pInstance->AddEnemyProjectile(this);
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::onDestroyed()
{
	GameManager::m_pInstance->RemoveEnemyProjectile(this);
}