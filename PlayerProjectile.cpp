#include "PlayerProjectile.h"
#include "GameManager.h"

PlayerProjectile::PlayerProjectile()
{
	SetTexture("Assets/Character/player_laser.png");
	SetSpeed(1000);
	GameManager::m_pInstance->AddPlayerProjectile(this);
}

PlayerProjectile::~PlayerProjectile()
{
	
}

void PlayerProjectile::onDestroyed()
{
	GameManager::m_pInstance->RemovePlayerProjectile(this);
}