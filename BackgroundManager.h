#pragma once
#include "GameObject.h"

class BackgroundManager
{
public:
	BackgroundManager();
	~BackgroundManager();

private:
	GameObject* m_pBackgroundSprite;
};

