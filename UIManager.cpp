#include "UIManager.h"
#include "PlayerObject.h"
#include "Game.h"

UIManager::UIManager()
{
	for (int i = 0; i < PlayerObject::m_nMaxLives; i++)
		addLifeSprite();
}

UIManager::~UIManager()
{

}

void UIManager::SetLives(const int nLives)
{
	int nDifference = nLives - m_aLifeSprites.size();

	if (nDifference > 0)
	{
		for (int i = 0; i < nDifference; i++)
			addLifeSprite();
	}
	else if (nDifference < 0)
	{
		for (int i = 0; i < -nDifference; i++)
			removeLifeSprite();
	}
}

void UIManager::addLifeSprite()
{
	GameObject* pLifeSprite = Game::AddGameObject<GameObject>();
	pLifeSprite->SetTexture("Assets/life.png");
	pLifeSprite->SetPosition(sf::Vector2f(36 * m_aLifeSprites.size() + 20, 20));
	m_aLifeSprites.push_back(pLifeSprite);
}

void UIManager::removeLifeSprite()
{
	const int nLastIndex = m_aLifeSprites.size() - 1;
	GameObject* pSprite = m_aLifeSprites[nLastIndex];
	Game::DestroyGameObject(pSprite);
	m_aLifeSprites.erase(m_aLifeSprites.begin() + nLastIndex);
}