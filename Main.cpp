#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Screen.h"

int main()
{
	Screen::Init(800, 600);
	sf::RenderWindow pWindow(sf::VideoMode(Screen::m_nScreenWidth, Screen::m_nScreenHeight), "Kieran Newland - Top Down Shooter");

	Game pGame = Game();

	sf::Event event;
	sf::Clock pClock;

	while (pWindow.isOpen())
	{
		while (pWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				pWindow.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			pWindow.close();

		sf::Time pTimeDelta = pClock.restart();
		pGame.Update(pTimeDelta.asSeconds());

		//Render
		pWindow.clear();

		pGame.Render(pWindow);

		pWindow.display();
	}

	pWindow.close();

	return 0;
}

