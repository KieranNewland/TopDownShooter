#include "GunController.h"
#include "Game.h"


GunController::GunController()
{
}

GunController::~GunController()
{
}

void GunController::Update(float nTimeDelta)
{
	m_nTimeUntilNextShot -= nTimeDelta;
}

void GunController::Shoot(sf::Vector2f pPosition)
{
	if (m_nTimeUntilNextShot > 0)
		return;

	Projectile *pProjectile = Game::AddGameObject<Projectile>();
	pProjectile->SetPosition(pPosition);
	pProjectile->SetDirection(sf::Vector2f(0, -1));
	pProjectile->SetSpeed(1000);
	m_aProjectiles.push_back(pProjectile);

	m_nTimeUntilNextShot = m_nTimeBetweenShots;
}
