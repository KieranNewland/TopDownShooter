#pragma once
#include <vector>
#include "EnemyObject.h"
#include "Projectile.h"

class LevelManager
{
public:
	LevelManager();
	~LevelManager();

	void Update(float nTimeDelta);

	void AddProjectile(Projectile* pProjectile) { m_aProjectiles.push_back(pProjectile); }
	void RemoveProjectile(Projectile* pProjectile);

	static LevelManager* m_pInstance;

private:
	std::vector<EnemyObject*> m_aEnemies;
	std::vector<Projectile*> m_aProjectiles;
};

