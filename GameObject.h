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
	void SetCenterAnchor(sf::Vector2f pCenter) { m_pCenterAnchor = pCenter; }
	sf::Vector2f GetPosition();

	sf::Vector2u GetSize() { return m_pTexture.getSize(); }

	virtual void Update(float nTimeDelta);

	const int getIndex() const { return m_nObjectId; }

	bool operator==(GameObject& pObject) const
	{
		return getIndex() == pObject.getIndex();
	}

private:
	sf::Sprite m_pSprite;
	sf::Texture m_pTexture;

	int m_nObjectId;
	static int m_nGameObjectIndex;

	sf::Vector2f m_pCenterAnchor;
};

