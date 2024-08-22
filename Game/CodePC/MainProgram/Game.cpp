#include "Game.h"
#include <iostream>

void Game::handleEvents()
{
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->window.close();
		}
	}
}

void Game::update()
{
	elapsedTimeSinceLastUpdate += clock.restart();
	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{
		elapsedTimeSinceLastUpdate -= timePerFrame;
		if (runGame == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeSinceLastAddedLaser > sf::seconds(30.0f))
			{
				laserHandler->addLaser(player->getBounds().left + 75.0f, player->getBounds().top + 10.0f);
				timeSinceLastAddedLaser = sf::seconds(0.0f);
				clock2.restart();
			}
			timeSinceLastAddedLaser += clock2.getElapsedTime();

			for (int i = 0; i < nrOfPlayerAstroid; i++)
			{
				playerAstroidList[i]->move();
			}

			this->laserHandler->laserMove();
			this->scoreboard->update();

			this->laserHandler->laserInsideWindow(WIDTH, HEIGHT);
			if (!this->player->insideWindow(WIDTH, HEIGHT))
			{
				float playerX = 0.0f;
				float playerY = 0.0f;

				if (this->player->getBounds().left <= 48)
				{
					playerX = 48.0f;
					playerY = this->player->getBounds().top;
				}
				if (this->player->getBounds().left >= WIDTH-48)
				{
					playerX = WIDTH-48.0f;
					playerY = this->player->getBounds().top;
				}
				if (this->player->getBounds().top <= 48)
				{
					playerX = this->player->getBounds().left + 48;
					playerY = 48;
				}
				if (this->player->getBounds().top >= HEIGHT-48)
				{
					playerX = this->player->getBounds().left + 48;
					playerY = HEIGHT - 48;
				}
				this->player->setPosition(playerX, playerY);
			}				

			if (!this->astroid->insideWindow(WIDTH, HEIGHT))
			{
				this->astroid->setPosition(WIDTH + 100, (float)(rand() % (int)HEIGHT));
			}

			for (int i = 0; i < laserHandler->getNrOfLaser(); i++)
			{
				if (this->astroid->collidedWith(&laserHandler->getLaser(i)))
				{
					this->astroid->setPosition(WIDTH + 100, (float)(rand() % (int)HEIGHT));
					laserHandler->removeLaser(i);
					this->scoreboard->addToCurrentPoint();
				}
			}

			if (this->astroid->collidedWith(this->player))
			{
				this->scoreboard->writeToFile();
				this->runGame = false;
			}
		}
	}	
}

void Game::render()
{
	this->window.clear();

	this->window.draw(*this->astroid);
	this->window.draw(*this->player);
	for (int i = 0; i < laserHandler->getNrOfLaser(); i++)
	{
		this->window.draw(laserHandler->getLaser(i));
	}
	this->window.draw(*this->scoreboard);

	this->window.display();
}

Game::Game()
	:window(sf::VideoMode(WIDTH, HEIGHT), "Space Game"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero),
	timeSinceLastAddedLaser(sf::Time::Zero)
{

	player = std::make_shared<Player>(WIDTH, HEIGHT);
	astroid = std::make_shared<Astroid>(WIDTH, HEIGHT);
	playerAstroidList[0] = player;
	playerAstroidList[1] = astroid;
	laserHandler = std::make_unique<LaserHandler>();
	scoreboard = std::make_unique<Scoreboard>();

	this->runGame = true;
}

Game::~Game()
{
}

void Game::run()
{
	while (this->window.isOpen())
	{
		handleEvents();
		update();
		render();
	}
}
