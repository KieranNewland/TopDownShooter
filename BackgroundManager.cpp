#include "BackgroundManager.h"
#include "Game.h"
#include "Screen.h"

BackgroundManager::BackgroundManager()
{
	m_pBackgroundSprite = Game::AddGameObject<GameObject>();
	m_pBackgroundSprite->SetTexture("Assets/Background/background.png");

	sf::Vector2u pCurrentSize = m_pBackgroundSprite->GetSize();
	float nDesiredScaleX = (float)Screen::m_nScreenWidth / pCurrentSize.x;
	float nDesiredScaleY = (float)Screen::m_nScreenHeight / pCurrentSize.y;
	m_pBackgroundSprite->SetScale(sf::Vector2f(nDesiredScaleX, nDesiredScaleY));
}

BackgroundManager::~BackgroundManager()
{

}