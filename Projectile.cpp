#include "Projectile.h"
#include "Game.h"
#include "GameManager.h"

Projectile::Projectile()
{
	SetCenterAnchor(sf::Vector2f(0.5f, 0));
}

Projectile::~Projectile()
{

}

void Projectile::SetDirection(sf::Vector2f pDirection)
{
	m_pDirection = pDirection;
}

void Projectile::Update(float nTimeDelta)
{
	//Move in the direction of travel
	sf::Vector2f pPosition = GetPosition();
	pPosition.x += m_pDirection.x * nTimeDelta * m_nTravelSpeed;
	pPosition.y += m_pDirection.y * nTimeDelta * m_nTravelSpeed;
	SetPosition(pPosition);

	if (pPosition.y < -100)
		destroyProjectile();
}

void Projectile::OnHit()
{
	destroyProjectile();
}

void Projectile::destroyProjectile()
{
	Game::DestroyGameObject(this);
	onDestroyed();
}