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

void Button::SetClicked(const bool clicked)
{
	if (clicked)
	{
		isClicked = true;
	}
}

void Button::StartPulse()
{
	isPulsing = true;
	increaseRgb = true;
}

void Button::ColorTransition(const float dt)
{
	if (isPulsing && increaseRgb)
	{
		IncreaseRGB(dt);
	}
	else if(isPulsing && decreaseRgb)
	{
		DecreaseRGB(dt);
	}
}

bool Button::IsPulsing() const
{
	return isPulsing;
}

void Button::Pulse(const float dt)
{
	if (isPulsing && increaseRgb)
	{
		IncreaseRGB(dt);
	}
	else if (isPulsing && decreaseRgb)
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
		auto r = color.r == rMax ? color.r : color.r + colorSteps;
		auto b = color.b == bMax ? color.b : color.b + colorSteps;
		auto g = color.g == gMax ? color.g : color.g + colorSteps;

		color.r = r > rMax ? rMax : r;
		color.g = g > gMax ? gMax : g;
		color.b = b > bMax ? bMax : b;

		if (color.r == rMax &&
			color.g == gMax &&
			color.b == bMax)
		{
			isClicked = false;
			increaseRgb = false;
			decreaseRgb = true;
		}

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
		auto r = color.r == rMin ? color.r : color.r - colorSteps;
		auto g = color.g == gMin ? color.g : color.g - colorSteps;
		auto b = color.b == bMin ? color.b : color.b - colorSteps;

		color.r = r < rMin ? rMin : r;
		color.g = g < gMin ? gMin : g;
		color.b = b < bMin ? bMin : b;

		if (color.r == rMin &&
			color.g == gMin &&
			color.b == bMin)
		{
			decreaseRgb = false;
			isPulsing = false;
		}
		shape.setFillColor(color);
	}
}
