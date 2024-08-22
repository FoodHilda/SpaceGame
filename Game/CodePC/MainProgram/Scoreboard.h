#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <fstream>


class Scoreboard :public sf::Drawable
{
public:
	Scoreboard();
	~Scoreboard();

	void addToCurrentPoint();
	void writeToFile();
	void readFromFileTopThree();
	void update();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Font* font;
	sf::Text* text;
	std::map<std::string, int> points;
};

#endif // !SCORE_H

