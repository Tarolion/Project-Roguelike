#include "SceneBase.h"

SceneBase::SceneBase()
{
	name = "#UNINITIALIZED#";
	sceneStatus = "";

	camera = new Camera();
	camera->MoveCamera(0, 0);

	textureAtlas = new TextureAtlas();
}

SceneBase::~SceneBase()
{

}

void SceneBase::Activate()
{
	sceneStatus = "";
	OnActivation();
}

void SceneBase::OnActivation()
{

}

void SceneBase::Deactivate()
{
	sceneStatus = "";
	OnDeactivation();
}

void SceneBase::OnDeactivation()
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
