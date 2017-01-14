#include "Game.h"

Game::Game()
{
	InitializeSystems();
}

Game::~Game()
{
	window = nullptr;
}

void Game::InitializeSystems()
{
	sceneManager = new SceneManager();
	sceneManager->AddScene(new OpeningCreditsScene());
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
			else
			{
				sceneManager->Process(ev);
			}
		}

		sceneManager->Update();

		window->clear();
		sceneManager->Draw(window);
		window->display();
	}

	running = false;
}

bool Game::IsGameRunning()
{
	return running;
}
