#include "LevelManager.h"
#include "Game.h"

LevelManager* LevelManager::m_pInstance;

LevelManager::LevelManager()
{
	m_pInstance = this;

	EnemyObject* pEnemyObject = Game::AddGameObject<EnemyObject>();
	pEnemyObject->SetPosition(sf::Vector2f(400, 100));
	m_aEnemies.push_back(pEnemyObject);
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

		for (int j = 0; j < m_aProjectiles.size(); j++)
		{
			if (pEnemyBox.intersects(m_aProjectiles[j]->GetBoundingBox()))
			{
				m_aEnemies[i]->OnHit();
				m_aProjectiles[i]->OnHit();
				break;
			}
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