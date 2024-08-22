#include "MovingObjects.h"

MovingObjects::MovingObjects(float xPos, float yPos, float speed, std::string filePath)
{
	this->speed = speed;
	this->texture.loadFromFile(filePath);
	this->sprite.setTexture(this->texture);
	setRotation(90.f);
}

MovingObjects::~MovingObjects()
{
}

bool MovingObjects::insideWindow(float width, float heigth) const
{
	bool yes = true;

	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width < 0 || this->sprite.getGlobalBounds().left > width ||
		this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height < 0 || this->sprite.getGlobalBounds().top > heigth)
	{
		yes = false;
	}
	return yes;
}

void MovingObjects::setPosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void MovingObjects::setRotation(float rotation)
{
	this->sprite.setRotation(rotation);
}

void MovingObjects::rotate(float rotation)
{
	this->sprite.rotate(rotation);
}

void MovingObjects::setOrigin(float x, float y)
{
	this->sprite.setOrigin(x, y);
}

void MovingObjects::moveSprite(float x, float y)
{
	this->sprite.move(x, y);
}

sf::FloatRect MovingObjects::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

float MovingObjects::getSpeed() const
{
	return this->speed;
}

void MovingObjects::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}
