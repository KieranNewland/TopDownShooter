#include "LevelManager.h"
#include "Game.h"

LevelManager* LevelManager::m_pInstance;

LevelManager::LevelManager()
{
	m_pInstance = this;

	m_pPlayerObject = Game::AddGameObject<PlayerObject>();
	m_pPlayerObject->SetPosition(sf::Vector2f(400, 500));

	for (int i = 0; i < 5; i++)
	{
		EnemyObject* pEnemyObject = Game::AddGameObject<EnemyObject>();
		pEnemyObject->SetPosition(sf::Vector2f(200 + i * 100, 100));
		m_aEnemies.push_back(pEnemyObject);
	}
}

LevelManager::~LevelManager()
{

}

void LevelManager::Update(float nTimeDelta)
{
	sf::FloatRect pEnemyBox;
	for (int i = 0; i < m_aEnemies.size(); i++)
	{
		pEnemyBox = m_aEnemies[i]->GetBoundingBox();

		//Collide with projectiles
		for (int j = 0; j < m_aProjectiles.size(); j++)
		{
			if (pEnemyBox.intersects(m_aProjectiles[j]->GetBoundingBox()))
			{
				m_aEnemies[i]->InflictDamage(1);
				m_aProjectiles[j]->OnHit();
				break;
			}
		}

		//Collide with player
		if (!m_pPlayerObject->GetDestroyedState() && pEnemyBox.intersects(m_pPlayerObject->GetBoundingBox()))
		{
			m_aEnemies[i]->InflictDamage(INT_MAX);
			m_pPlayerObject->InflictDamage(1);
		}
	}
}

void LevelManager::RemoveProjectile(Projectile* pProjectile)
{
	for (int i = 0; i < m_aProjectiles.size(); i++)
	{
		if (m_aProjectiles[i] == pProjectile)
		{
			m_aProjectiles.erase(m_aProjectiles.begin() + i);
			return;
		}
	}
}

void LevelManager::DestroyEnemy(EnemyObject* pEnemy)
{
	for (int i = 0; i < m_aEnemies.size(); i++)
	{
		if (m_aEnemies[i] == pEnemy)
		{
			m_aEnemies.erase(m_aEnemies.begin() + i);
			return;
		}
	}
}