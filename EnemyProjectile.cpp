#include "EnemyProjectile.h"
#include "GameManager.h"
#include "LaserExplosion.h"
#include "Game.h"


EnemyProjectile::EnemyProjectile()
{
	SetTexture("Assets/Character/enemy_laser.png");
	SetSpeed(500);
	SetCenterAnchor(sf::Vector2f(0.5f, 1));
	GameManager::m_pInstance->AddEnemyProjectile(this);
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::onDestroyed()
{
	LaserExplosion* pExplosion = Game::AddGameObject<LaserExplosion>();
	pExplosion->Init("enemy", GetPosition());

	GameManager::m_pInstance->RemoveEnemyProjectile(this);
}