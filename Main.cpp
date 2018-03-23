#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow pWindow(sf::VideoMode(800, 600), "Kieran Newland - Top Down Shooter");

	Game pGame = Game();

	sf::Event event;

	while (pWindow.isOpen())
	{
		while (pWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				pWindow.close();
		}

		pGame.Update();

		//Render
		pWindow.clear();

		pGame.Render(pWindow);

		pWindow.display();
	}

	pWindow.close();

	return 0;
}

