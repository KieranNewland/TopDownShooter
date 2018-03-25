#include "GameManager.h"
#include "Game.h"

GameManager* GameManager::m_pInstance;

GameManager::GameManager()
{
	m_pInstance = this;

	m_pPlayerObject = Game::AddGameObject<PlayerObject>();
	m_pPlayerObject->SetPosition(sf::Vector2f(400, 500));

	//Spawn enemies
	for (int i = 0; i < 5; i++)
	{
		EnemyObject* pEnemyObject = Game::AddGameObject<EnemyObject>();
		pEnemyObject->SetPosition(sf::Vector2f(200 + i * 100, 100));
		m_aEnemies.push_back(pEnemyObject);
	}
}

GameManager::~GameManager()
{

}

void GameManager::Update(float nTimeDelta)
{
	sf::FloatRect pEnemyBox;
	for (int i = 0; i < m_aEnemies.size(); i++)
	{
		pEnemyBox = m_aEnemies[i]->GetBoundingBox();

		//Collide projectiles with enemies
		for (int j = 0; j < m_aProjectiles.size(); j++)
		{
			if (pEnemyBox.intersects(m_aProjectiles[j]->GetBoundingBox()))
			{
				m_aEnemies[i]->InflictDamage(1);
				m_aProjectiles[j]->OnHit();
				break;
			}
		}

		//Collide player with enemies
		if (!m_pPlayerObject->GetDestroyedState() && pEnemyBox.intersects(m_pPlayerObject->GetBoundingBox()))
		{
			m_aEnemies[i]->InflictDamage(INT_MAX);
			m_pPlayerObject->InflictDamage(1);
			m_pUI.SetLives(m_pPlayerObject->GetHealth());
		}
	}
}

void GameManager::RemoveProjectile(Projectile* pProjectile)
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

void GameManager::DestroyEnemy(EnemyObject* pEnemy)
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