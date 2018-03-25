#pragma once
#include "Projectile.h"

class EnemyProjectile : public Projectile
{
public:
	EnemyProjectile();
	~EnemyProjectile();

protected:
	void onDestroyed() override;
};

