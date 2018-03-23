#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "GameObject.h"

class Game
{
public:
	Game();
	~Game();

public:
	void Update();
	void Render(sf::RenderWindow&);

private:
	GameObject* m_pGameObject;

	static std::vector<GameObject*> m_aGameObjects;

public:
	static GameObject *AddGameObject(const char* szTexturePath)
	{
		GameObject* pGameObject = new GameObject(szTexturePath);
		m_aGameObjects.push_back(pGameObject);

		return pGameObject;
	}

	static void RemoveGameObject(GameObject &pObject)
	{
		for (int i = 0; i < m_aGameObjects.size(); i++)
		{
			if (m_aGameObjects[i] == &pObject)
			{
				m_aGameObjects.erase(m_aGameObjects.begin() + i);
				return;
			}
		}
	}
};

