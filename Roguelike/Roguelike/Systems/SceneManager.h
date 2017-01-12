#ifndef _SYSTEM_SCENEMANAGER_H_
#define _SYSTEM_SCENEMANAGER_H_
//

#include <iostream>
#include <vector>

#include "../Includes.h"

#include "../Scenes/SceneBase.h"

class SceneManager
{
private:

protected:
	std::string name;
	std::vector<SceneBase*> scenes;

	unsigned int currentScene;

public:
	SceneManager();
	~SceneManager();

	SceneBase* GetCurrentScene();
	void ChangeScene(unsigned int scene);
	void AddScene(SceneBase* scene);

	void Process(sf::Event& ev);
	void Update();
	void Draw(sf::RenderWindow* window);
};
//
#endif // !_SYSTEM_SCENEMANAGER_H_