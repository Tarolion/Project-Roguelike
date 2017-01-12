#ifndef _GAME_H_
#define _GAME_H_
//
#include "Includes.h"
#include "Systems\SceneManager.h"
#include "Scenes\SceneBase.h"

class Game
{
private:
	bool running;

	sf::RenderWindow*	window;
	SceneManager*		sceneManager;

protected:

public:
	Game();
	~Game();

	void InitializeSystems();
	void GameLoop();

	bool IsGameRunning();
};



//
#endif // !_GAME_H_
