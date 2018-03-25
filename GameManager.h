#pragma once
#include <vector>
#include "EnemyObject.h"
#include "Projectile.h"
#include "PlayerObject.h"
#include "BackgroundManager.h"
#include "UIManager.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update(float nTimeDelta);

	void AddProjectile(Projectile* pProjectile) { m_aProjectiles.push_back(pProjectile); }
	void RemoveProjectile(Projectile* pProjectile);

	void DestroyEnemy(EnemyObject*);

	static GameManager* m_pInstance;

private:
	std::vector<EnemyObject*> m_aEnemies;
	std::vector<Projectile*> m_aProjectiles;

	BackgroundManager m_pBackground;
	UIManager m_pUI;
	PlayerObject* m_pPlayerObject;
};

