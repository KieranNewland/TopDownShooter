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
	sf::Vector2u pSize = GetSize();

	pPosition.x -= pSize.x * m_pCenterAnchor.x;
	pPosition.y -= pSize.y * m_pCenterAnchor.y;

	m_pSprite.setPosition(pPosition);
}

sf::Vector2f GameObject::GetPosition()
{
	sf::Vector2f pPosition = m_pSprite.getPosition();
	sf::Vector2u pSize = GetSize();

	pPosition.x += m_pCenterAnchor.x * pSize.x;
	pPosition.y += m_pCenterAnchor.y * pSize.y;
	
	return pPosition;
}