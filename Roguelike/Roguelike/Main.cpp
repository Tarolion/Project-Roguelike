#include <iostream>

#include "Settings.h"
#include "Includes.h"
#include "Game.h"

int main()
{
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Welcome to the Roguelike Project" << std::endl;
	std::cout << "Programmed by John" << std::endl;
	std::cout << "Art by Chris" << std::endl;
	std::cout << "Placeholder Art by DragonDePlatino and DawnBringer" << std::endl;
	std::cout << "Powered by SFML" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << "Loading Settings File..." << std::endl;
	if (!Settings::LoadSettingsFile())
	{
		std::cout << "Failed to load settings file..." << std::endl;
		std::cout << "Game Closing..." << std::endl;
		system("Pause");
		return -1;
	}

	std::cout << "Starting Game..." << std::endl;

#ifndef _DEBUG
	// If we are not debugging the game. I.e playing the released version.
	// Hide the console until the game is over.
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif // !_DEBUG

	// Create Game
	Game* game = new Game();

	// Begin the GameLoop
	game->GameLoop();

#ifndef _DEBUG
	// If we are not debugging the game. I.e playing the released version.
	// Now that the game is over we can show it again, just incase there was any errors that caused the game to close.
	ShowWindow(GetConsoleWindow(), SW_SHOW);
#endif // !_DEBUG

	std::cout << "Game Closing..." << std::endl;
	system("Pause");
	return 0;
}