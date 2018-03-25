#pragma once
#include <vector>
#include "SFML\Graphics.hpp"
class PlayerGunController
{
public:
	PlayerGunController();
	~PlayerGunController();

public:
	void Update(float);

	void Shoot(sf::Vector2f);

private:
	float m_nTimeUntilNextShot;
	const float m_nTimeBetweenShots = 0.1f;
};

