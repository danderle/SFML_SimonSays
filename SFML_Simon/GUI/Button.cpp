#include "Button.h"

unsigned int Button::totalIndex = 0;

Button::Button(const float width, const float height, const float xPos, const float yPos)
	: Button({width, height}, {xPos, yPos})
{
}

Button::Button(const sf::Vector2f size, const sf::Vector2f position)
	:
	gMax(-1),
	gMin(-1),
	bMax(-1),
	bMin(-1),
	rMax(-1),
	rMin(-1)
{
	shape.setSize(size);
	shape.setPosition(position);
	index = totalIndex;
	totalIndex++;
}

const bool Button::Contains(sf::Vector2f position)
{
	return shape.getGlobalBounds().contains(position);
}

const bool Button::Contains(sf::Vector2i position)
{
	return Contains(sf::Vector2f(position));
}

void Button::SetColor(const sf::Color color)
{
	startingColor = color;
	shape.setFillColor(startingColor);
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

void Button::StartPulse()
{
	isPulsing = true;
	isFinished = false;
	increaseRgb = true;
}

void Button::StartContinousPulse()
{
	continousPulse = true;
	StartPulse();
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
	//std::cout << index << " Pulsing " << std::boolalpha << isPulsing << std::endl;
	return isPulsing;
}

bool Button::IsFinished() const
{
	return isFinished;
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

void Button::Reset()
{
	isFinished = false;
	isPulsing = false;
	increaseRgb = false;
	decreaseRgb = false;
	continousPulse = false;
	SetColor(startingColor);
}

const unsigned int Button::GetIndex() const
{
	return index;
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
	assert(rMax != -1);
	assert(gMax != -1);
	assert(bMax != -1);
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
			increaseRgb = false;
			decreaseRgb = true;
		}

		shape.setFillColor(color);
	}
}

void Button::DecreaseRGB(const float dt)
{
	assert(rMax != -1);
	assert(gMax != -1);
	assert(bMax != -1);
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
			isFinished = true;
			if (continousPulse)
			{
				isFinished = false;
				isPulsing = true;
				increaseRgb = true;
			}
		}
		shape.setFillColor(color);
	}
}
