#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

sf::Vector2i Camera::GetPosition()
{
	return position;
}

void Camera::MoveCamera(int x, int y)
{
	position.x = x - Settings::WindowWidth / 2;
	position.y = y - Settings::WindowHeight / 2;
}

void Camera::MoveCamera(sf::Vector2i vec)
{
	position = vec - sf::Vector2i(Settings::WindowWidth / 2, Settings::WindowHeight / 2);
}
