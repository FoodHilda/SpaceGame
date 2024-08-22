#ifndef MOVINGOBJECTS_H
#define MOVINGOBJECTS_H
#include <SFML/Graphics.hpp>

class MovingObjects :public sf::Drawable
{
public:
	MovingObjects(float xPos, float yPos, float speed, std::string filePath);
	~MovingObjects();

	bool insideWindow(float width, float heigth) const;
	virtual void move() = 0;
	void setPosition(float x, float y);
	void setRotation(float rotation);
	void rotate(float rotation);
	void setOrigin(float x, float y);
	void moveSprite(float x, float y);

	sf::FloatRect getBounds() const;

	float getSpeed() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
};
#endif // !MOVINGOBJECTS_H

