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

void Button::SetMinRGB(const sf::Uint8 r, const sf::Uint8 g, const sf::Uint8 b)
{
	rMin = r;
	gMin = g;
	bMin = b;
}

void Button::SetMaxRGB(const sf::Uint8 r, const sf::Uint8 g, const sf::Uint8 b)
{
	rMax = r;
	gMax = g;
	bMax = b;
}

void Button::SetHover(const bool isHovering)
{
	hover = isHovering;
}

void Button::ColorTransition(const float dt)
{
	if (hover)
	{
		IncreaseRGB(dt);
	}
	else
	{
		DecreaseRGB(dt);
	}
}

sf::FloatRect Button::GetRect() const
{
	return shape.getGlobalBounds();
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}


//Private Functions

void Button::IncreaseRGB(const float dt)
{
	colortimePassed += dt;
	if (colortimePassed >= colorTransitionTimeout)
	{
		colortimePassed = 0.f;
		auto color = shape.getFillColor();
		auto r = color.r == rMax ? color.r : color.r + 1;
		auto b = color.b == bMax ? color.b : color.b + 1;
		auto g = color.g == gMax ? color.g : color.g + 1;

		color.r = r > rMax ? rMax : r;
		color.g = g > gMax ? gMax : g;
		color.b = b > bMax ? bMax : b;

		shape.setFillColor(color);
	}
}

void Button::DecreaseRGB(const float dt)
{
	colortimePassed += dt;
	if (colortimePassed >= colorTransitionTimeout)
	{
		colortimePassed = 0.f; 
		auto color = shape.getFillColor();
		auto r = color.r == rMin ? color.r : color.r - 1;
		auto g = color.g == gMin ? color.g : color.g - 1;
		auto b = color.b == bMin ? color.b : color.b - 1;

		color.r = r < rMin ? rMin : r;
		color.g = g < gMin ? gMin : g;
		color.b = b < bMin ? bMin : b;

		shape.setFillColor(color);
	}
}
