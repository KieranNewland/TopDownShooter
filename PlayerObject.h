#pragma once
#include "Character.h"
#include "GunController.h"

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

	GunController m_pGun;
};

