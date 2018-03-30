#pragma once
#include "Character.h"
#include "PlayerGunController.h"

class PlayerObject : public Character
{
public:
	PlayerObject();
	~PlayerObject();

public:
	void Update(float nDeltaTime) override;

	static int m_nMaxLives;

protected:
	void onHit() override;
	void onDeath() override;

private:
	void moveInDirection(float&, float, float);

	float m_nXAcceleration, m_nYAcceleration;
	const float m_nAccelerationStrength = 1.2f;
	const float m_nDecelerationStrength = 6;

	const float m_nShipRadius = 50;

	PlayerGunController m_pGun;
};

