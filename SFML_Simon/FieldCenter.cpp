#include "FieldCenter.h"

FieldCenter::FieldCenter(const sf::Vector2f windowSize)
	:
	circle(circleRadius),
	centerPoint(windowSize.x/2, windowSize.y/2)
{
	SetupCircle(windowSize);
	SetupTexts(windowSize);
}

bool FieldCenter::Contains(const sf::Vector2f mousePosition) const
{
	return circle.getGlobalBounds().contains(mousePosition);
}

void FieldCenter::Draw(sf::RenderWindow& window)
{
	window.draw(circle);
	firstLine.Draw(window);
	secondLine.Draw(window);
}

void FieldCenter::SetState(const State state)
{
	currentState = state;
	switch (currentState)
	{
	case State::PressToStart:
		firstLine.setString("Press red");
		secondLine.setString("to start");
		SetTextColor(pressStartColor);
		StopBlink();
		break;
	case State::SimonSays:
		firstLine.setString("Simon");
		secondLine.setString("says");
		SetTextColor(simonsSaysColor);
		break;
	case State::PleaseRepeat:
		firstLine.setString("Please");
		secondLine.setString("repeat");
		SetTextColor(pleaseRepeatColor);
		break;
	case State::GameOver:
		firstLine.setString("Game");
		secondLine.setString("over");
		SetTextColor(gameOverColor);
		Blink();
		break;
	case State::PressToContinue:
		firstLine.setString("Press to");
		secondLine.setString("continue");
		SetTextColor(gameOverColor);
		Blink();
		break;
	}
	CenterText();
}

const State FieldCenter::GetState() const
{
	return currentState;
}

void FieldCenter::ColorTransition(const float dt)
{
	if (toggleText)
	{
		toggletimePassed += dt;
		if (toggletimePassed >= toggleTransitionTimeout)
		{
			ToggleText();
			toggletimePassed = 0;
		}
	}
	if (isBlinking && increaseRgb)
	{
		IncreaseRGB(dt);
	}
	else if (isBlinking && decreaseRgb)
	{
		DecreaseRGB(dt);
	}
}


//Private Methods

void FieldCenter::ToggleText()
{
	if (currentState == State::GameOver)
	{
		SetState(State::PressToContinue);
	}
	else
	{
		SetState(State::GameOver);
	}
}

void FieldCenter::Blink()
{
	toggleText = true;
	isBlinking = true;
	increaseRgb = true;
}

void FieldCenter::StopBlink()
{
	toggleText = false;
	isBlinking = false;
	increaseRgb = false;
	decreaseRgb = false;
}

void FieldCenter::CenterText()
{
	firstLine.SetOriginToCenter();
	secondLine.SetOriginToCenter();
	firstLine.setPosition(centerPoint.x, centerPoint.y - firstLine.GetHeight() * 3 / 4);
	secondLine.setPosition(centerPoint.x, centerPoint.y + firstLine.GetHeight() * 3 / 4);
}

void FieldCenter::SetRgbMin(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b)
{
	rMin = r;
	gMin = g;
	bMin = b;
}

void FieldCenter::SetRgbMax(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b)
{
	rMax = r;
	gMax = g;
	bMax = b;
}

void FieldCenter::SetTextColor(const sf::Color color)
{
	firstLine.SetColor(color);
	secondLine.SetColor(color);
}

void FieldCenter::SetTextOutline(const sf::Color color, const float thickness)
{
	firstLine.SetOutlineColor(sf::Color::Black);
	firstLine.SetOutlineThickness(thickness);
	secondLine.SetOutlineColor(sf::Color::Black);
	secondLine.SetOutlineThickness(thickness);
}

void FieldCenter::SetupCircle(const sf::Vector2f windowSize)
{
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(centerPoint);
	circle.setFillColor(defaultColor);
	SetRgbMin(defaultColor.r, defaultColor.g, defaultColor.b);
	SetRgbMax(sf::Color::White.r, sf::Color::White.g, sf::Color::White.b);

	circle.setOutlineThickness(circleOutlineThickness);
	circle.setOutlineColor(outlineColor);
}

void FieldCenter::SetupTexts(const sf::Vector2f windowSize)
{
	firstLine.setString("Press red");
	secondLine.setString("to start");
	firstLine.SetOriginToCenter();
	secondLine.SetOriginToCenter();
	firstLine.setPosition(windowSize.x / 2, windowSize.y / 2 - firstLine.GetHeight() * 3/4);
	secondLine.setPosition(windowSize.x / 2, windowSize.y / 2 + secondLine.GetHeight() * 3/4);
	SetTextColor(pressStartColor);
	SetTextOutline(outlineColor, textOutlineThickness);
}

void FieldCenter::DecreaseRGB(const float dt)
{
	assert(rMax != -1);
	assert(gMax != -1);
	assert(bMax != -1);
	colortimePassed += dt;
	if (colortimePassed >= colorTransitionTimeout)
	{
		colortimePassed = 0.f;
		auto color = circle.getFillColor();
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
			increaseRgb = true;
		}
		circle.setFillColor(color);
	}
}

void FieldCenter::IncreaseRGB(const float dt)
{
	assert(rMax != -1);
	assert(gMax != -1);
	assert(bMax != -1);
	colortimePassed += dt;
	if (colortimePassed >= colorTransitionTimeout)
	{
		colortimePassed = 0.f;
		auto color = circle.getFillColor();
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

		circle.setFillColor(color);
	}
}

