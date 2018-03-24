#include "EnemyObject.h"

EnemyObject::EnemyObject()
{
	SetTexture("Assets/enemy.png");
	SetCenterAnchor(sf::Vector2f(0.5f, 0.5f));
}

EnemyObject::~EnemyObject()
{
}

void EnemyObject::OnHit()
{

}