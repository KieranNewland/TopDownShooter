#pragma once
#include "Character.h"

class EnemyObject : public Character
{
public:
	EnemyObject();
	~EnemyObject();

protected:
	void onHit() override;
	void onDeath() override;

private:
};

