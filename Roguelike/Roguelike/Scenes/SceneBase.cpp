#include "SceneBase.h"

SceneBase::SceneBase()
{
	camera = new Camera();
	camera->MoveCamera(0, 0);
}

SceneBase::~SceneBase()
{

}

void SceneBase::Process(sf::Event & ev)
{

}

void SceneBase::Update()
{

}

void SceneBase::Draw(sf::RenderWindow* window)
{
	window->setTitle("Current Scene: " + name);
}
