#include "FieldCenter.h"

FieldCenter::FieldCenter(const sf::Vector2f windowSize)
	:
	circle(circleRadius)
{
	SetupCircle(windowSize);
	SetupTexts(windowSize);
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
		SetTextColor(sf::Color::Black);
		break;
	case Turn::SimonSays:
		firstLine.SetString("Simon");
		secondLine.SetString("says");
		SetTextColor({ 255, 0, 255 });
		break;
	case Turn::PleaseRepeat:
		firstLine.SetString("Please");
		secondLine.SetString("repeat");
		SetTextColor({ 255, 128, 0 });
		break;
	}
}


//Private Methods

void FieldCenter::SetTextColor(const sf::Color color)
{
	firstLine.SetColor(color);
	secondLine.SetColor(color);
}

void FieldCenter::SetupCircle(const sf::Vector2f windowSize)
{
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(windowSize.x / 2, windowSize.y / 2);
	circle.setFillColor({ 192,192,192 });
	circle.setOutlineThickness(-8);
	circle.setOutlineColor(sf::Color::Black);
}

void FieldCenter::SetupTexts(const sf::Vector2f windowSize)
{
	firstLine.SetString("Press red");
	secondLine.SetString("to start");
	firstLine.SetCenterPosition(windowSize.x / 2, windowSize.y / 2 - firstLine.GetHeight() * 3/4);
	secondLine.SetCenterPosition(windowSize.x / 2, windowSize.y / 2 + secondLine.GetHeight() * 3/4);
	SetTextColor(sf::Color::Black);
}
