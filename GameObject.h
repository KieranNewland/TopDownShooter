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

	void SetPosition(const float, const float);
	void SetPosition(sf::Vector2f);
	void SetScale(const sf::Vector2f);
	void SetCenterAnchor(sf::Vector2f);
	void SetRotation(float);
	sf::Vector2f GetPosition();

	void SetAlpha(float);

	sf::Vector2u GetSize() { return m_pTexture.getSize(); }
	sf::FloatRect GetBoundingBox() { return m_pSprite.getGlobalBounds(); }

	int GetRenderLayer() { return m_nRenderLayer; }
	void SetRenderLayer(int);

	void Destroy() { m_bDestroyed = true; }
	bool GetDestroyedState() { return m_bDestroyed; }

	virtual void Update(float);

	const int getIndex() const { return m_nObjectId; }

	bool operator==(GameObject& pObject) const
	{
		return getIndex() == pObject.getIndex();
	}

private:
	sf::Sprite m_pSprite;
	sf::Texture m_pTexture;

	int m_nObjectId;
	int m_nRenderLayer;
	static int m_nGameObjectIndex;

	bool m_bDestroyed;
};

