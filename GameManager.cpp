#include "GameManager.h"
#include "Game.h"

GameManager* GameManager::m_pInstance;

GameManager::GameManager()
{
	m_pInstance = this;

	m_pPlayerObject = Game::AddGameObject<PlayerObject>();
	m_pPlayerObject->SetPosition(sf::Vector2f(400, 500));

	m_pEnemySpawner.SpawnNextWave();
}

GameManager::~GameManager()
{

}

void GameManager::Update(float nTimeDelta)
{
	sf::FloatRect pBoundingBox;
	for (int i = 0; i < m_aEnemies.size(); i++)
	{
		pBoundingBox = m_aEnemies[i]->GetBoundingBox();

		//Collide projectiles with enemies
		for (int j = 0; j < m_aPlayerProjectiles.size(); j++)
		{
			if (pBoundingBox.intersects(m_aPlayerProjectiles[j]->GetBoundingBox()))
			{
				m_aEnemies[i]->InflictDamage(1);
				m_aPlayerProjectiles[j]->OnHit();
				break;
			}
		}

		//Collide player with enemies
		if (!m_pPlayerObject->GetDestroyedState() && pBoundingBox.intersects(m_pPlayerObject->GetBoundingBox()))
		{
			m_aEnemies[i]->InflictDamage(INT_MAX);
			m_pPlayerObject->InflictDamage(1);
			m_pUI.SetLives(m_pPlayerObject->GetHealth());
		}
	}

	//Collide player with enemy projectiles
	if (!m_pPlayerObject->GetDestroyedState())
	{
		pBoundingBox = m_pPlayerObject->GetBoundingBox();
		for (int i = 0; i < m_aEnemyProjectiles.size(); i++)
		{
			if (m_aEnemyProjectiles[i]->GetBoundingBox().intersects(pBoundingBox))
			{
				m_aEnemyProjectiles[i]->OnHit();
				m_pPlayerObject->InflictDamage(1);
				m_pUI.SetLives(m_pPlayerObject->GetHealth());
			}
		}
	}
}

void GameManager::RemovePlayerProjectile(PlayerProjectile* pProjectile)
{
	for (int i = 0; i < m_aPlayerProjectiles.size(); i++)
	{
		if (m_aPlayerProjectiles[i] == pProjectile)
		{
			m_aPlayerProjectiles.erase(m_aPlayerProjectiles.begin() + i);
			return;
		}
	}
}

void GameManager::RemoveEnemyProjectile(EnemyProjectile* pProjectile)
{
	for (int i = 0; i < m_aEnemyProjectiles.size(); i++)
	{
		if (m_aEnemyProjectiles[i] == pProjectile)
		{
			m_aEnemyProjectiles.erase(m_aEnemyProjectiles.begin() + i);
			return;
		}
	}
}

void GameManager::AddEnemy(EnemyObject* pEnemy)
{
	m_aEnemies.push_back(pEnemy);
}

void GameManager::DestroyEnemy(EnemyObject* pEnemy)
{
	for (int i = 0; i < m_aEnemies.size(); i++)
	{
		if (m_aEnemies[i] == pEnemy)
		{
			m_aEnemies.erase(m_aEnemies.begin() + i);
			break;
		}
	}

	if (m_aEnemies.size() == 0)
		m_pEnemySpawner.SpawnNextWave();
}