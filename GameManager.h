#pragma once
#include <vector>
#include "EnemyObject.h"
#include "PlayerProjectile.h"
#include "EnemyProjectile.h"
#include "PlayerObject.h"
#include "BackgroundManager.h"
#include "UIManager.h"
#include "EnemySpawner.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update(float nTimeDelta);

	void AddPlayerProjectile(PlayerProjectile* pProjectile) { m_aPlayerProjectiles.push_back(pProjectile); }
	void RemovePlayerProjectile(PlayerProjectile* pProjectile);

	void AddEnemyProjectile(EnemyProjectile* pProjectile) { m_aEnemyProjectiles.push_back(pProjectile); }
	void RemoveEnemyProjectile(EnemyProjectile* pProjectile);

	void AddEnemy(EnemyObject*);
	void DestroyEnemy(EnemyObject*);

	static GameManager* m_pInstance;

private:
	std::vector<EnemyObject*> m_aEnemies;
	std::vector<PlayerProjectile*> m_aPlayerProjectiles;
	std::vector<EnemyProjectile*> m_aEnemyProjectiles;

	BackgroundManager m_pBackground;
	UIManager m_pUI;
	PlayerObject* m_pPlayerObject;
	EnemySpawner m_pEnemySpawner;
};

