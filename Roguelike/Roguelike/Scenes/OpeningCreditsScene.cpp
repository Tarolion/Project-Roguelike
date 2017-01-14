#include "OpeningCreditsScene.h"

OpeningCreditsScene::OpeningCreditsScene() : SceneBase()
{
	name = "OpeningCredits";
	Initialize();
}

OpeningCreditsScene::~OpeningCreditsScene()
{
}

void OpeningCreditsScene::Initialize()
{
	// Prepare Timing
	fadeInTime = 3;
	holdTime = 2;
	fadeOutTime = 1;
	phase = 0;
	currentCreditsTexture = 0;

	// Now Prepare Textures... Load from files and store in vector.
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(Settings::GameDirectoryPath + "\\Resources\\SFMLCredits.png");	// SFML Credits
	_creditsTextures.push_back(texture);
	texture = nullptr;
	
	texture = new sf::Texture();
	texture->loadFromFile(Settings::GameDirectoryPath + "\\Resources\\DawnLikeCredits.png");	// DawnLike Credits
	_creditsTextures.push_back(texture);
	texture = nullptr;

	// Restart the animation clock ahead of drawing sprite.
	animationClock.restart();
}

void OpeningCreditsScene::OnActivation()
{
	Initialize();
}

void OpeningCreditsScene::OnDeactivation()
{
	_creditsTextures.clear();
}

sf::Texture* OpeningCreditsScene::GetCurrentTexture()
{
	if (currentCreditsTexture < _creditsTextures.size())
	{
		return _creditsTextures[currentCreditsTexture];
	}
	
	return nullptr;
}


void OpeningCreditsScene::Process(sf::Event & ev)
{

}

void OpeningCreditsScene::Update()
{
	float time = animationClock.getElapsedTime().asSeconds();
	// Fade In Animation.
	if (phase == 0)
	{
		if (time < fadeInTime)
		{
			float a = time / fadeInTime * 255;
			_sprite.setColor(sf::Color(255, 255, 255, a));
		}
		else
		{
			_sprite.setColor(sf::Color(255, 255, 255, 255));
			phase = 1;
			animationClock.restart();
		}

	}
	// Hold Animation.
	else if (phase == 1)
	{
		if (time < holdTime)
		{
		}
		else
		{
			phase = 2;
			animationClock.restart();
		}
	}
	// Fade Out Animation
	else if (phase == 2)
	{
		if (time < fadeOutTime)
		{
			float a = time / fadeOutTime * 255;
			_sprite.setColor(sf::Color(255, 255, 255, 255 - a));
		}
		else
		{
			_sprite.setColor(sf::Color(255, 255, 255, 0));
			phase = 3;
			animationClock.restart();
		}
	}
	// Switch to next Texture.
	else if (phase == 3)
	{
		currentCreditsTexture += 1;
		if (currentCreditsTexture > _creditsTextures.size() - 1)
		{
			// we have run out of credits Textures.... STop Animations...
			phase = 4;
			// TODO: Change to next Scene in SceneManager.
			sceneStatus = "CHANGESCENE NEXT"; // Go to next Scene
		}
		else
		{
			// We have more to go... restart.
			phase = 0;
			animationClock.restart();
		}
	}
}

void OpeningCreditsScene::Draw(sf::RenderWindow * window)
{
	if (GetCurrentTexture() == nullptr)
	{
		return;
	}

	camera->MoveCamera(0, 0);

	// Prepare Texture
	sf::Texture currentTexture = *(sf::Texture*)GetCurrentTexture();

	_sprite.setTexture(currentTexture);
	_sprite.setTextureRect(sf::IntRect(0, 0, currentTexture.getSize().x, currentTexture.getSize().y));
	_sprite.setOrigin(currentTexture.getSize().x / 2, currentTexture.getSize().y / 2);
	_sprite.setPosition(Settings::WindowWidth / 2, Settings::WindowHeight / 2);

	window->draw(_sprite);
}
