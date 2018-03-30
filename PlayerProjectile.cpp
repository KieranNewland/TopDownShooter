#include "PlayerProjectile.h"
#include "GameManager.h"
#include "LaserExplosion.h"
#include "Game.h"

PlayerProjectile::PlayerProjectile()
{
	SetTexture("Assets/Character/player_laser.png");
	SetCenterAnchor(sf::Vector2f(0.5f, 0));
	SetSpeed(1000);
	GameManager::m_pInstance->AddPlayerProjectile(this);
}

PlayerProjectile::~PlayerProjectile()
{
	
}

void PlayerProjectile::onDestroyed()
{
	LaserExplosion* pExplosion = Game::AddGameObject<LaserExplosion>();
	pExplosion->Init("player", GetPosition());

	GameManager::m_pInstance->RemovePlayerProjectile(this);
}