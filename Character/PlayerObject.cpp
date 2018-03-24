#include "PlayerObject.h"
#include "SFML\Graphics.hpp"
#include <algorithm>

PlayerObject::PlayerObject()
{
	SetTexture("Assets/player.png");
	SetCenterAnchor(sf::Vector2f(0.5f, 0.5f));
	SetRenderLayer(1);
}

PlayerObject::~PlayerObject()
{

}

void PlayerObject::Update(float nTimeDelta)
{
	//Get key input
	float nXDirection = 0, nYDirection = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		nXDirection--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		nXDirection++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		nYDirection--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		nYDirection++;

	//Move in the direction of the input
	moveInDirection(m_nXAcceleration, nXDirection, nTimeDelta);
	moveInDirection(m_nYAcceleration, nYDirection, nTimeDelta);

	sf::Vector2f pPosition = GetPosition();
	pPosition.x += m_nXAcceleration;
	pPosition.y += m_nYAcceleration;
	SetPosition(pPosition);

	//Update gun
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_pGun.Shoot(pPosition);

	m_pGun.Update(nTimeDelta);
}

void PlayerObject::moveInDirection(float& nAcceleration, float nAmt, float nTimeDelta)
{
	nAcceleration += nAmt * m_nAccelerationStrength * nTimeDelta;

	//Decelerate - can probably be made to look nicer
	float nDecelerationAmt = nTimeDelta * m_nDecelerationStrength;
	if (nAcceleration > 0)
	{
		nAcceleration -= nDecelerationAmt * abs(nAcceleration);

		if (nAcceleration < 0)
			nAcceleration = 0;
	}

	if (nAcceleration < 0)
	{
		nAcceleration += nDecelerationAmt * abs(nAcceleration);

		if (nAcceleration > 0)
			nAcceleration = 0;
	}

	//Clamp at maximum velocity
	if (nAcceleration < -1)
		nAcceleration = -1;

	if (nAcceleration > 1)
		nAcceleration = 1;
}