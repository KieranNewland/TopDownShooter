#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(const char*);
	~GameObject();

public:
	void Render(sf::RenderWindow&);
	void SetPosition(sf::Vector2f);

	int getIndex() { return m_nObjectId; }

	bool operator==(GameObject& pObject) 
	{
		return getIndex() == pObject.getIndex();
	}

private:
	sf::Sprite m_pSprite;
	sf::Texture m_pTexture;

	int m_nObjectId;
	static int m_nGameObjectIndex;
};

