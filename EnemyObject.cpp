#include "EnemyObject.h"
#include "Game.h"

EnemyObject::EnemyObject() : Character(5)
{
	SetTexture("Assets/Character/enemy.png");
	SetCenterAnchor(sf::Vector2f(0.5f, 0.5f));

	resetTimeUntilShot();
}

EnemyObject::~EnemyObject()
{
}

void EnemyObject::Update(float nTimeDelta)
{
	m_nTimeUntilShot -= nTimeDelta;

	if (m_nTimeUntilShot > 0)
		return;

	EnemyProjectile *pProjectile = Game::AddGameObject<EnemyProjectile>();
	pProjectile->SetPosition(GetPosition());
	pProjectile->SetDirection(sf::Vector2f(0, 1));

	resetTimeUntilShot();
}

void EnemyObject::onHit()
{

}

void EnemyObject::onDeath()
{
	GameManager::m_pInstance->DestroyEnemy(this);
	Game::DestroyGameObject(this);
}

void EnemyObject::resetTimeUntilShot()
{
	m_nTimeUntilShot = m_nTimeBetweenShots + ((float)rand() / RAND_MAX) * m_nRandomTimeBetweenShots;
}