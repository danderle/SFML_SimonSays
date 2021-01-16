#include "FieldCenter.h"

FieldCenter::FieldCenter(const sf::Vector2f windowSize)
	:
	circle(circleRadius)
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

void FieldCenter::SetTurn(const Turn turn)
{
	switch (turn)
	{
	case Turn::PressToStart:
		firstLine.SetString("Press red");
		secondLine.SetString("to start");
		SetTextColor(pressStartColor);
		break;
	case Turn::SimonSays:
		firstLine.SetString("Simon");
		secondLine.SetString("says");
		SetTextColor(simonsSaysColor);
		break;
	case Turn::PleaseRepeat:
		firstLine.SetString("Please");
		secondLine.SetString("repeat");
		SetTextColor(pleaseRepeatColor);
		break;
	}
}


//Private Methods

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
	circle.setPosition(windowSize.x / 2, windowSize.y / 2);
	circle.setFillColor({ 192,192,192 });
	circle.setOutlineThickness(circleOutlineThickness);
	circle.setOutlineColor(outlineColor);
}

void FieldCenter::SetupTexts(const sf::Vector2f windowSize)
{
	firstLine.SetString("Press red");
	secondLine.SetString("to start");
	firstLine.SetCenterPosition(windowSize.x / 2, windowSize.y / 2 - firstLine.GetHeight() * 3/4);
	secondLine.SetCenterPosition(windowSize.x / 2, windowSize.y / 2 + secondLine.GetHeight() * 3/4);
	SetTextColor(pressStartColor);
	SetTextOutline(outlineColor, textOutlineThickness);
}
