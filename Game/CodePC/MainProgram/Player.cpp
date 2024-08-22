#include "Player.h"

Player::Player(float windowWidth, float windowHeight, float speed) : MovingObjects(windowWidth, windowHeight, speed, "../Images/spaceship.png")
{
	MovingObjects::setPosition(windowWidth / 4, windowHeight / 2);
	MovingObjects::setRotation(90.f);
}

Player::~Player()
{
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		MovingObjects::moveSprite(-MovingObjects::getSpeed(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		MovingObjects::moveSprite(MovingObjects::getSpeed(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		MovingObjects::moveSprite(0, MovingObjects::getSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		MovingObjects::moveSprite(0, -MovingObjects::getSpeed());
	}
}
