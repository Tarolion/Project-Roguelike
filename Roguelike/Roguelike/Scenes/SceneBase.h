#ifndef _SCENE_SCENEBASE_H_
#define _SCENE_SCENEBASE_H_
//

#include "../Includes.h"
#include "../Systems/Camera.h"

class SceneBase
{
private:

protected:
	std::string name;
	Camera* camera;

public:
	SceneBase();
	~SceneBase();

	void Process(sf::Event& ev);
	void Update();
	void Draw(sf::RenderWindow* window);
};
//
#endif // !_SCENE_SCENEBASE_H_