#include "PlayerGunController.h"
#include "Game.h"
#include "PlayerProjectile.h"

PlayerGunController::PlayerGunController()
{
}

PlayerGunController::~PlayerGunController()
{

}

void PlayerGunController::Update(float nTimeDelta)
{
	m_nTimeUntilNextShot -= nTimeDelta;
}

void PlayerGunController::Shoot(sf::Vector2f pPosition)
{
	if (m_nTimeUntilNextShot > 0)
		return;

	PlayerProjectile *pProjectile = Game::AddGameObject<PlayerProjectile>();
	pProjectile->SetPosition(pPosition);
	pProjectile->SetDirection(sf::Vector2f(0, -1));

	m_nTimeUntilNextShot = m_nTimeBetweenShots;
}
