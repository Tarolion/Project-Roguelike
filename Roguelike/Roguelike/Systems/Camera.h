#ifndef _SYSTEM_CAMERA_H_
#define _SYSTEM_CAMERA_H_
//
#include "../Includes.h"
#include "../Settings.h"

class Camera
{
private:

protected:
	sf::Vector2i position;

public:
	Camera();
	~Camera();

	sf::Vector2i GetPosition();
	void MoveCamera(int x, int y);
	void MoveCamera(sf::Vector2i vec);
};

//
#endif // !_SYSTEM_CAMERA_H_
