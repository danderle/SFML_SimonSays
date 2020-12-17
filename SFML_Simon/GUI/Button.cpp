#include "Button.h"

Button::Button(const float width, const float height, const float xPos, const float yPos)
	: Button({width, height}, {xPos, yPos})
{
}

Button::Button(const sf::Vector2f size, const sf::Vector2f position)
{
	shape.setSize(size);
	shape.setPosition(position);
}

void Button::SetColor(const sf::Color color)
{
	shape.setFillColor(color);
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
