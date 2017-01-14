#ifndef _SYSTEM_TEXTUREATLAS_H_
#define _SYSTEM_TEXTUREATLAS_H_
//
#include "../Includes.h"
#include "../Settings.h"

typedef enum
{
	FLOOR_TL = 0,
	FLOOR_T = 1,
	FLOOR_TR = 2,
	FLOOR_TLR = 3,
	FLOOR_TLRB = 5,
	FLOOR_L = 7,
	FLOOR_C = 8,
	FLOOR_R = 9,
	FLOOR_LR = 10,
	FLOOR_TLB = 11,
	FLOOR_TB = 12,
	FLOOR_TRB = 13,
	FLOOR_RB = 14,
	FLOOR_B = 15,
	FLOOR_LRB = 16,


	WALL_T_TL		= 20,
	WALL_T_C		= 21,
	WALL_T_TR		= 22,
	WALL_FILL		= 23,
	WALL_T_LRB		= 24,
	WALL_C_L		= 27,
	WALL_C_R		= 27,
	WALL_B			= 28,
	WALL_C_TRB		= 30,
	WALL_C_TLRB		= 31,
	WALL_C_TLB		= 32,
	WALL_B_BL		= 34,
	WALL_B_BR		= 36,
	WALL_B_TLR		= 37,

} TEXTURES;

class TextureAtlas
{
private:

protected:
	std::vector<sf::Texture*> _textures;

public:
	TextureAtlas();
	~TextureAtlas();

	void LoadTextureFile();
	sf::Texture* GetTexture(TEXTURES value);
	sf::Texture* GetTexture(int value);
};



//
#endif // !_SYSTEM_TEXTUREATLAS_H_
