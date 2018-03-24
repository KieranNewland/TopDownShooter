#include "Game.h"

std::multimap<const int, GameObject*> Game::m_aGameObjects;
std::vector<GameObject*> Game::m_aDestroyed;
std::vector<GameObject*> Game::m_aQueuedForLayerUpdate;

Game::Game()
{
	m_pGameObject = Game::AddGameObject<PlayerObject>();
}

Game::~Game()
{
	for (std::pair<const int, GameObject*> pGameObject : m_aGameObjects)
		delete pGameObject.second;
}

void Game::Update(float nTimeDelta)
{
	for (std::pair<const int, GameObject*> pGameObject : m_aGameObjects)
	{
		if (pGameObject.second->GetDestroyed())
			continue;

		pGameObject.second->Update(nTimeDelta);
	}

	deleteDestroyedGameObjects();
	updateFlaggedLayers();
}

void Game::Render(sf::RenderWindow &pWindow)
{
	for (std::pair<const int, GameObject*> pGameObject : m_aGameObjects)
	{
		if (pGameObject.second->GetDestroyed())
			continue;

		pGameObject.second->Render(pWindow);
	}
}

//Static functions
void Game::DestroyGameObject(GameObject* pObject)
{
	m_aDestroyed.push_back(pObject);
	pObject->Destroy();
}

void Game::UpdateGameObjectLayer(GameObject* pObject)
{
	m_aQueuedForLayerUpdate.push_back(pObject);
}

void Game::deleteDestroyedGameObjects()
{
	if (m_aDestroyed.size() == 0)
		return;

	GameObject* pObject;
	for (int i = 0; i < m_aDestroyed.size(); i++)
	{
		pObject = m_aDestroyed[i];

		for (auto pIterator = m_aGameObjects.begin(); pIterator != m_aGameObjects.end(); pIterator++)
		{
			if (pIterator->second == pObject)
			{
				m_aGameObjects.erase(pIterator);
				break;
			}
		}
	}

	m_aDestroyed.clear();
}

void Game::updateFlaggedLayers()
{
	if (m_aQueuedForLayerUpdate.size() == 0)
		return;

	GameObject* pObject;
	for (int i = 0; i < m_aQueuedForLayerUpdate.size(); i++)
	{
		pObject = m_aQueuedForLayerUpdate[i];

		for (auto pIterator = m_aGameObjects.begin(); pIterator != m_aGameObjects.end(); pIterator++)
		{
			if (pIterator->second == pObject)
			{
				m_aGameObjects.erase(pIterator);
				m_aGameObjects.insert(std::pair<const int, GameObject*>(pObject->GetRenderLayer(), pObject));
				break;
			}
		}
	}

	m_aQueuedForLayerUpdate.clear();
}