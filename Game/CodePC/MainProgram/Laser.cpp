#include "Laser.h"
#include <iostream>

Laser::Laser(float xPos, float yPos, float speed) : MovingObjects(xPos, yPos, speed, "../Images/blasterbolt.png")
{
	MovingObjects::setPosition(xPos, yPos);
	MovingObjects::setRotation(90);
}

Laser::~Laser()
{
}

void Laser::move()
{
	MovingObjects::moveSprite(MovingObjects::getSpeed(), 0);
}
