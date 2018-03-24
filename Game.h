#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <unordered_map>
#include "GameObject.h"
#include "PlayerObject.h"

class Game
{
public:
	Game();
	~Game();

public:
	void Update(float);
	void Render(sf::RenderWindow&);

private:
	PlayerObject * m_pGameObject;

	//Static functions
public:
	static std::vector<GameObject*> m_aGameObjects;
	//static std::unordered_map<GameObject*> m_aGameObjects;

	template<class T>
	static T *AddGameObject()
	{
		static_assert(std::is_base_of<GameObject, T>::value, "Trying to create a gameobject which isn't derived from GameObject)");

		GameObject* pGameObject = new T();
		m_aGameObjects.push_back((GameObject*)pGameObject);

		return (T*)pGameObject;
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

