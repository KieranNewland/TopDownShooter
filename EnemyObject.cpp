#include "EnemyObject.h"
#include "Game.h"

EnemyObject::EnemyObject() : Character(5)
{
	SetTexture("Assets/enemy.png");
	SetCenterAnchor(sf::Vector2f(0.5f, 0.5f));
}

EnemyObject::~EnemyObject()
{
}

void EnemyObject::onHit()
{

}

void EnemyObject::onDeath()
{
	LevelManager::m_pInstance->DestroyEnemy(this);
	Game::DestroyGameObject(this);
}