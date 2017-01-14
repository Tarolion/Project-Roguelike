#ifndef _SCENE_OPENINGCREDITS_H_
#define _SCENE_OPENINGCREDITS_H_
//

#include "../Includes.h"
#include "../Scenes/SceneBase.h"
#include "../Systems/Camera.h"

class OpeningCreditsScene : public SceneBase
{
private:

protected:
	std::vector<sf::Texture*> _creditsTextures;
	sf::Sprite _sprite;
	sf::Clock animationClock;

	float			fadeInTime;				// How long in seconds it will take for the sprite to go from 0 alpha to 255 alpha.
	float			holdTime;				// How long in seconds the sprite will hold 255 alpha
	float			fadeOutTime;			// How long in seconds the sprite will take to go from 255 alpha to 0
	unsigned int	phase;					// which step is the sprite currently doing, 0 = fadeIn, 1 = hold, 2 = fadeOut, 3 = next Sprite.
	unsigned int	currentCreditsTexture;	// which texture are we currently showing.

	sf::Texture* GetCurrentTexture();

public:
	OpeningCreditsScene();
	~OpeningCreditsScene();

	void Initialize();

	void OnActivation();
	void OnDeactivation();
	void Process(sf::Event& ev);
	void Update();
	void Draw(sf::RenderWindow* window);

};
//
#endif // !_SCENE_SCENEBASE_H_