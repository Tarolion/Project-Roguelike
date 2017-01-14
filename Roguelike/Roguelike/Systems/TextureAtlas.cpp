#include "TextureAtlas.h"

TextureAtlas::TextureAtlas()
{
	LoadTextureFile();
}

TextureAtlas::~TextureAtlas()
{
}

void TextureAtlas::LoadTextureFile()
{
	sf::Image atlas;
	atlas.loadFromFile(Settings::GameDirectoryPath + "\\Resources\\TextureAtlas.png");

	for (int i = 0; i < atlas.getSize().x / Settings::TileSize; i++)
	{
		for (int j = 0; j < atlas.getSize().y / Settings::TileSize; j++)
		{
			sf::IntRect subImage = sf::IntRect(i*Settings::TileSize, j*Settings::TileSize, Settings::TileSize, Settings::TileSize);

			sf::Texture* texture = new sf::Texture();
			texture->loadFromImage(atlas, subImage);

			_textures.push_back(texture);
		}
	}
}

sf::Texture* TextureAtlas::GetTexture(TEXTURES value)
{
	int index = (int)value;
	return _textures[index];
}
sf::Texture* TextureAtlas::GetTexture(int value)
{
	if (value < _textures.size())
	{
		return _textures[value];
	}
	
	return nullptr;
}
