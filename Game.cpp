#include "Game.h"

std::vector<GameObject*> Game::m_aGameObjects = std::vector<GameObject*>();

Game::Game()
{
	m_pGameObject = Game::AddGameObject("Assets/player.png");
}

Game::~Game()
{
	for (int i = 0; i < m_aGameObjects.size(); i++)
		delete m_aGameObjects[i];
}

void Game::Update()
{

}

void Game::Render(sf::RenderWindow &pWindow)
{
	for (int i = 0; i < m_aGameObjects.size(); i++)
		m_aGameObjects[i]->Render(pWindow);
}