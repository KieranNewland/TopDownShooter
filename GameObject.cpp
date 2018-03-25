#include "GameObject.h"
#include "Game.h"

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

void GameObject::SetCenterAnchor(sf::Vector2f pCenter)
{
	m_pCenterAnchor = pCenter;
	SetPosition(m_pSprite.getPosition());
}

void GameObject::SetPosition(const float nX, const float nY)
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

void GameObject::SetRenderLayer(int nLayer)
{
	m_nRenderLayer = nLayer;
	Game::UpdateGameObjectLayer(this);
}

void GameObject::SetScale(const sf::Vector2f pScale)
{
	m_pSprite.setScale(pScale);
}