#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <list>
#include <map>
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
	static std::multimap<const int, GameObject*> m_aGameObjects;
	static std::vector<GameObject*> m_aDestroyed;
	static std::vector<GameObject*> m_aQueuedForLayerUpdate;

	template<class T>
	static T *AddGameObject()
	{
		static_assert(std::is_base_of<GameObject, T>::value, "Trying to create a gameobject which isn't derived from GameObject.");

		GameObject* pGameObject = new T();
		m_aGameObjects.insert(std::pair<const int, GameObject*>(pGameObject->GetRenderLayer(), pGameObject));

		return (T*)pGameObject;
	}

	static void DestroyGameObject(GameObject *pObject);
	static void UpdateGameObjectLayer(GameObject* pObject);

private:
	static void deleteDestroyedGameObjects();
	static void updateFlaggedLayers();
};

