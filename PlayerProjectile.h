#pragma once
#include "Projectile.h"

class PlayerProjectile : public Projectile
{
public:
	PlayerProjectile();
	~PlayerProjectile();

protected:
	void onDestroyed() override;
};

