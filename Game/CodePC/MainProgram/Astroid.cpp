#include "Astroid.h"


Astroid::Astroid(float windowWidth, float windowHeight, float radius, float speed) : MovingObjects(windowWidth, windowHeight, speed, "../Images/Asteroid.png")
{
	MovingObjects::setOrigin(75.0f, 100.0f);
	setPosition(windowWidth + 100, (float)(rand() % (int)windowHeight));
}

Astroid::~Astroid()
{
}

void Astroid::move()
{
	MovingObjects::moveSprite(-MovingObjects::getSpeed(), 0);
	MovingObjects::rotate(0.5f);
}

