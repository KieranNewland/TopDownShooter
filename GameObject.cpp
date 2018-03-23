#include "GameObject.h"

int GameObject::m_nGameObjectIndex;

GameObject::GameObject()
{
	m_nObjectId = m_nGameObjectIndex++;
}

void GameObject::SetTexture(const char* szTexturePath)
{
	if (!m_pTexture.loadFromFile(szTexturePath))
	{
		exit(EXIT_FAILURE);
	}

	m_pSprite.setTexture(m_pTexture);
}

GameObject::~GameObject()
{

}

void GameObject::Update(float nDeltaTime)
{

}

void GameObject::Render(sf::RenderWindow &pWindow)
{
	pWindow.draw(m_pSprite);
}

void GameObject::SetPosition(float nX, float nY)
{
	SetPosition(sf::Vector2f(nX, nY));
}

void GameObject::SetPosition(sf::Vector2f pPosition)
{
	m_nXPosition = pPosition.x;
	m_nYPosition = pPosition.y;
	m_pSprite.setPosition(pPosition);
}