#pragma once
#include "Character.h"

class EnemyObject : public Character
{
public:
	EnemyObject();
	~EnemyObject();

public:
	void Update(float) override;

protected:
	void onHit() override;
	void onDeath() override;

private:
	void resetTimeUntilShot();

	const float m_nTimeBetweenShots = 3;
	const float m_nRandomTimeBetweenShots = 2;
	float m_nTimeUntilShot;
};

