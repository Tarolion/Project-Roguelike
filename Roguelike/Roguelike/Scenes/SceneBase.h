#ifndef _SCENE_SCENEBASE_H_
#define _SCENE_SCENEBASE_H_
//

#include "../Includes.h"
#include "../Systems/Camera.h"
#include "../Systems/TextureAtlas.h"

class SceneBase
{
private:

protected:
	std::string name;
	Camera* camera;
	std::string sceneStatus; 
	// The SceneStatus is like a command that will be read by the SceneManager each tick.
	// The idea being that it will tell the sceneManager that we are ready to move onto another Scene, or quit game etc.
	
	TextureAtlas* textureAtlas;

public:
	SceneBase();
	~SceneBase();

	void Activate();
	virtual void OnActivation();
	void Deactivate();
	virtual void OnDeactivation();

	virtual void Process(sf::Event& ev);
	virtual void Update();
	virtual void Draw(sf::RenderWindow* window);
};
//
#endif // !_SCENE_SCENEBASE_H_