#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile();
	~Projectile();

public:
	void Update(float) override;

	void SetDirection(sf::Vector2f);
	void SetSpeed(float nSpeed) { m_nTravelSpeed = nSpeed; }

private:
	sf::Vector2f m_pDirection;
	float m_nTravelSpeed;
};

