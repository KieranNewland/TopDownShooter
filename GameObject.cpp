#include "GameObject.h"

int GameObject::m_nGameObjectIndex;

GameObject::GameObject(const char* szTexturePath)
{
	m_nObjectId = m_nGameObjectIndex++;

	if (!m_pTexture.loadFromFile(szTexturePath))
	{
		exit(EXIT_FAILURE);
	}

	m_pSprite.setTexture(m_pTexture);
}

GameObject::~GameObject()
{

}

void GameObject::Render(sf::RenderWindow &pWindow)
{
	pWindow.draw(m_pSprite);
}

void GameObject::SetPosition(sf::Vector2f pPosition)
{
	m_pSprite.setPosition(pPosition);
}