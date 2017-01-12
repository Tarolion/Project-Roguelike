#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	window = nullptr;
}

void Game::GameLoop()
{
	// Create a new Window
	window = new sf::RenderWindow(sf::VideoMode(Settings::WindowWidth, Settings::WindowHeight), "");

	running = true;

	// Now wait for the window to close...
	while (window->isOpen())
	{
		sf::Event ev;
		while (window->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window->close();
			}
		}

		window->clear();

		window->display();
	}

	running = false;
}

bool Game::IsGameRunning()
{
	return running;
}
