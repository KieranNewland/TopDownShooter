#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(int nHealth);
	~Character();

public:
	void InflictDamage(int);

	int GetHealth() { return m_nCurrentHealth; }

protected:
	const int m_nMaxHealth;
	int m_nCurrentHealth;

	virtual void onHit() = 0;
	virtual void onDeath() = 0;
};

