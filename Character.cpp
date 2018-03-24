#include "Character.h"



Character::Character(int nHealth) : m_nMaxHealth(nHealth)
{
	m_nCurrentHealth = m_nMaxHealth;
}


Character::~Character()
{
}

void Character::InflictDamage(int nDamage)
{
	m_nCurrentHealth -= nDamage;

	if (m_nCurrentHealth > 0)
		onHit();
	else
		onDeath();
}