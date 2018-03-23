#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

public:
	void SetTexture(const char*);
	void Render(sf::RenderWindow&);

	void SetPosition(float nX, float nY);
	void SetPosition(sf::Vector2f);

	virtual void Update(float nTimeDelta);

	int getIndex() { return m_nObjectId; }

	bool operator==(GameObject& pObject) 
	{
		return getIndex() == pObject.getIndex();
	}

protected:
	float m_nXPosition, m_nYPosition;

private:
	sf::Sprite m_pSprite;
	sf::Texture m_pTexture;

	int m_nObjectId;
	static int m_nGameObjectIndex;
};

