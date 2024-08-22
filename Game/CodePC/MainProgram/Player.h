#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"

class Player :public MovingObjects
{
public:
	Player(float windowWidth, float windowHeight, float speed = 10.0f);
	~Player();
	virtual void move() override;
};
