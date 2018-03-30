#include "LaserExplosion.h"
#include "Game.h"

LaserExplosion::LaserExplosion()
{
	SetRenderLayer(3);
}

LaserExplosion::~LaserExplosion()
{
}

void LaserExplosion::Init(std::string szType, sf::Vector2f pPos)
{
	std::string pPath = "Assets/Character/" + szType + "_laser_hit.png";
	SetTexture(pPath.c_str());
	SetCenterAnchor(sf::Vector2f(0.5f, 0.5f));

	SetPosition(pPos);
}

void LaserExplosion::Update(float nTimeDelta)
{
	m_nTimeAlive += nTimeDelta;

	SetRotation(m_nTimeAlive * m_nRotationSpeed);

	//Calculate scale
	float nScale = pow(m_nTimeAlive, 2) / m_nScaleSpeed;

	if (nScale > 1)
		nScale = 1;

	SetScale(sf::Vector2f(nScale, nScale));

	//Calculate alpha
	float nAlpha = 1;

	if (m_nTimeAlive > m_nAlphaTime)
		nAlpha = 1 - ((m_nTimeAlive - m_nAlphaTime) / m_nMaxTimeAlive);

	SetAlpha(nAlpha);

	if (m_nTimeAlive > m_nMaxTimeAlive)
		Game::DestroyGameObject(this);
}