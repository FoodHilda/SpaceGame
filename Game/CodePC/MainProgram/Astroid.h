#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"

class Astroid :public MovingObjects
{
public:
	Astroid(float windowWidth, float windowHeight, float radius = 5.0f, float speed = 5.0f);
	~Astroid();
	virtual void move() override;
	template <typename T>
	bool collidedWith(const T& collidedObjekt) const;
};

template<typename T>
inline bool Astroid::collidedWith(const T& collidedObjekt) const
{
	return MovingObjects::getBounds().intersects(collidedObjekt->getBounds());
}
