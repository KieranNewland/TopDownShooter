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
	sf::Vector2u pSize = GetSize();
	m_pSprite.setOrigin(sf::Vector2f(pSize.x * pCenter.x, pSize.y * pCenter.y));
	SetPosition(m_pSprite.getPosition());
}

void GameObject::SetPosition(const float nX, const float nY)
{
	SetPosition(sf::Vector2f(nX, nY));
}

void GameObject::SetPosition(sf::Vector2f pPosition)
{
	m_pSprite.setPosition(pPosition);
}

void GameObject::SetRotation(float nRotation)
{
	m_pSprite.setRotation(nRotation);
}

sf::Vector2f GameObject::GetPosition()
{
	sf::Vector2f pPosition = m_pSprite.getPosition();
	sf::Vector2u pSize = GetSize();
	
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

void GameObject::SetAlpha(float nAlpha)
{
	sf::Color pColour = m_pSprite.getColor();
	pColour.a = nAlpha * 255;
	m_pSprite.setColor(pColour);
}