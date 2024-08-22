#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Laser.h"
#include "Astroid.h"
#include "LaserHandler.h"
#include "Scoreboard.h"
#include <memory>


class Game
{
private:
	static const int WIDTH = 1500;
	static const int HEIGHT = 800;
private:
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Clock clock2;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;
	sf::Time timeSinceLastAddedLaser;

	static const int nrOfPlayerAstroid = 2;

	std::shared_ptr<Astroid> astroid;
	std::shared_ptr<Player> player;
	std::shared_ptr<MovingObjects> playerAstroidList[nrOfPlayerAstroid];
	std::unique_ptr<LaserHandler> laserHandler;
	std::unique_ptr<Scoreboard> scoreboard;

	bool runGame;
	
	void handleEvents();
	void update();
	void render();

public:
	Game();
	~Game();
	void run(); 
};
