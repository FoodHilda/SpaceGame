#pragma once
#include <SFML/Graphics.hpp>
#include "Astroid.h"
#include "MovingObjects.h"
#include <string>

class Laser :public MovingObjects
{
public:
	Laser(float xPos = 0.0f, float yPos = 0.0f, float speed = 10.0f);
	~Laser();
	virtual void move() override;
};
