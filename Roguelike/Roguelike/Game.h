#ifndef _GAME_H_
#define _GAME_H_
//
#include "Includes.h"

class Game
{
private:
	bool running;

	sf::RenderWindow*	window;

protected:

public:
	Game();
	~Game();

	void GameLoop();

	bool IsGameRunning();
};



//
#endif // !_GAME_H_
