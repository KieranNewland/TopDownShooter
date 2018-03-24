#pragma once
#include <vector>
#include "Projectile.h"
class GunController
{
public:
	GunController();
	~GunController();

public:
	void Update(float);

	void Shoot(sf::Vector2f);

private:
	float m_nTimeUntilNextShot;
	const float m_nTimeBetweenShots = 0.2f;

	std::vector<Projectile*> m_aProjectiles;
};

