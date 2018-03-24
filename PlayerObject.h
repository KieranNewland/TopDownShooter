#pragma once
#include "GameObject.h"
#include "GunController.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject();
	~PlayerObject();

public:
	void Update(float nDeltaTime) override;

private:
	void moveInDirection(float&, float, float);

	float m_nXAcceleration, m_nYAcceleration;
	const float m_nAccelerationStrength = 1.2f;
	const float m_nDecelerationStrength = 6;

	GunController m_pGun;
};

