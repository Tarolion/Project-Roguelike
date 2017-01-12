#include "SceneManager.h"

SceneManager::SceneManager()
{
	currentScene = 0;
}
SceneManager::~SceneManager()
{
	scenes.clear();
}

SceneBase* SceneManager::GetCurrentScene()
{
	if (currentScene < scenes.size())
	{
		return scenes[currentScene];
	}

	return nullptr;
}

void SceneManager::ChangeScene(unsigned int scene)
{

}

void SceneManager::AddScene(SceneBase * scene)
{
	scenes.push_back(scene);
}

void SceneManager::Process(sf::Event & ev)
{
	SceneBase* scene = GetCurrentScene();
	scene->Process(ev);
}

void SceneManager::Update()
{
	SceneBase* scene = GetCurrentScene();
	scene->Update();
}

void SceneManager::Draw(sf::RenderWindow* window)
{
	SceneBase* scene = GetCurrentScene();
	scene->Draw(window);
}
