#include "LaserHandler.h"

LaserHandler::LaserHandler()
{
	this->cap = 10;
	this->nrOfLasers = 0;
	laser = new Laser*[cap];
}

LaserHandler::~LaserHandler()
{
	for (int i = 0; i < nrOfLasers; i++)
	{
		delete laser[i];
	}
	delete[] laser;
}

void LaserHandler::addLaser(float xPos, float yPos)
{
	if (nrOfLasers < cap)
	{
		laser[nrOfLasers] = new Laser(xPos, yPos);
		nrOfLasers++;
	}
}

void LaserHandler::removeLaser(int id)
{
	delete laser[id];
	laser[id] = laser[nrOfLasers - 1];
        	nrOfLasers--;
}

void LaserHandler::laserInsideWindow(float width, float heigth)
{
	int* listOfLasersToRemove = new int[nrOfLasers];
	int nrOfLasersToRemove = 0;
	for (int i = 0; i < nrOfLasers; i++)
	{
		if (!laser[i]->insideWindow(width, heigth))
		{
			listOfLasersToRemove[nrOfLasersToRemove] = i;
			nrOfLasersToRemove++;
		}
	}
	for (int i = 0; i < nrOfLasersToRemove; i++)
	{
		removeLaser(listOfLasersToRemove[i]);
	}
	delete[] listOfLasersToRemove;
}

void LaserHandler::laserMove()
{
	for (int i = 0; i < nrOfLasers; i++)
	{
		laser[i]->move();
	}
}

int LaserHandler::getNrOfLaser() const
{
	return this->nrOfLasers;
}

Laser& LaserHandler::getLaser(int id) const
{
	return *laser[id];
}
