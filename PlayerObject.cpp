#include "PlayerObject.h"
#include <algorithm>

PlayerObject::PlayerObject()
{
	SetTexture("Assets/player.png");
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Update(float nTimeDelta)
{
	//Get key input
	int nXDirection = 0, nYDirection = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		nXDirection--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		nXDirection++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		nYDirection--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		nYDirection++;

	moveInDirection(m_nXAcceleration, nXDirection, nTimeDelta);
	moveInDirection(m_nYAcceleration, nYDirection, nTimeDelta);

	SetPosition(m_nXPosition + m_nXAcceleration, m_nYPosition + m_nYAcceleration);
}

void PlayerObject::moveInDirection(float& nAcceleration, float nAmt, float nTimeDelta)
{
	float nAccelerationStrength = nAmt * m_nAccelerationStrength * nTimeDelta;
	nAcceleration += nAccelerationStrength;

	//Decelerate
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

void PlayerObject::updateGraphics()
{

}