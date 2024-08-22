#include "Scoreboard.h"
#include <iostream>

Scoreboard::Scoreboard()
{
	this->font = new sf::Font;
	this->font->loadFromFile("../Fonts/Aller_Bd.ttf");
	text = new sf::Text();
	text->setFont(*font);
	text->setStyle(sf::Text::Bold);
	text->setCharacterSize(24);
	text->setFillColor(sf::Color::White);

	points["1"] = 0;
	points["2"] = 0;
	points["3"] = 0;
	points["current"] = 0;

	readFromFileTopThree();
	text->setString("HIGHSCORES:\n 1. " + std::to_string(points["1"]) + "\n 2. " + std::to_string(points["2"]) + "\n 3. " + std::to_string(points["3"]) + "\n YOU: " + std::to_string(points["current"]));
}

Scoreboard::~Scoreboard()
{
	delete font;
	delete text;
}

void Scoreboard::addToCurrentPoint()
{
	points["current"]++;
}

void Scoreboard::writeToFile()
{
	std::ofstream outStream;
	outStream.open("../TextFiles/highscores.txt", std::ios_base::app);
	if (outStream.is_open())
	{
		outStream << points["current"] << std::endl;
	}
	outStream.close();
}

void Scoreboard::readFromFileTopThree()
{	 
	std::ifstream inStream("../TextFiles/highscores.txt");
	if (inStream.is_open())
	{
		std::string highscore;
		while (inStream >> highscore)
		{
			int filePoints = stoi(highscore);
			if (points["1"] < filePoints)
			{
				points["2"] = points["1"];
				points["1"] = filePoints;
			}
			else if (points["2"] < filePoints)
			{
				points["3"] = points["2"];
				points["2"] = filePoints;
			}
			else if (points["3"]< filePoints)
			{
				points["3"] = filePoints;
			}
		}
		inStream.close();
	}
}

void Scoreboard::update()
{
	text->setString("HIGHSCORES:\n 1. " + std::to_string(points["1"]) + "\n 2. " + std::to_string(points["2"]) + "\n 3. " + std::to_string(points["3"]) + "\n YOU: " + std::to_string(points["current"]));
}

void Scoreboard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*this->text);
	
}
