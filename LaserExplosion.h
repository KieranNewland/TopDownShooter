#pragma once
#include "GameObject.h"
#include <string>

class LaserExplosion : public GameObject
{
public:
	LaserExplosion();
	~LaserExplosion();

public:
	void Init(std::string, sf::Vector2f);
	void Update(float) override;

private:
	float m_nTimeAlive;
	const float m_nMaxTimeAlive = 0.5f;
	const float m_nRotationSpeed = 100;
	const float m_nScaleSpeed = 0.1f;
	const float m_nAlphaTime = 0.2f;
};