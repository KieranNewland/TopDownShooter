#pragma once
#include <vector>
#include "GameObject.h"

class UIManager
{
public:
	UIManager();
	~UIManager();

public:
	void SetLives(const int);

private:
	void addLifeSprite();
	void removeLifeSprite();

	std::vector<GameObject*> m_aLifeSprites;
};

