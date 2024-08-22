#pragma once
#include "Laser.h"
#include <memory>

class LaserHandler
{
public:
	LaserHandler();
	~LaserHandler();

	void addLaser(float xPos, float yPos);
	void removeLaser(int id);
	void laserInsideWindow(float width, float heigth);
	void laserMove();

	int getNrOfLaser() const;
	Laser& getLaser(int id) const;

private:
	Laser** laser;
	int cap;
	int nrOfLasers;
};
