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
	case Turn::GameOver:
		firstLine.SetString("Game");
		secondLine.SetString("over");
		SetTextColor(gameOverColor);
		break;
	}
	CenterText();
}


//Private Methods


void FieldCenter::CenterText()
{
	firstLine.SetOriginToCenter();
	secondLine.SetOriginToCenter();
	firstLine.SetPosition(centerPoint.x, centerPoint.y - firstLine.GetHeight() * 3 / 4);
	secondLine.SetPosition(centerPoint.x, centerPoint.y + firstLine.GetHeight() * 3 / 4);
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
	circle.setFillColor({ 192,192,192 });
	circle.setOutlineThickness(circleOutlineThickness);
	circle.setOutlineColor(outlineColor);
}

void FieldCenter::SetupTexts(const sf::Vector2f windowSize)
{
	firstLine.SetString("Press red");
	secondLine.SetString("to start");
	firstLine.SetOriginToCenter();
	secondLine.SetOriginToCenter();
	firstLine.SetPosition(windowSize.x / 2, windowSize.y / 2 - firstLine.GetHeight() * 3/4);
	secondLine.SetPosition(windowSize.x / 2, windowSize.y / 2 + secondLine.GetHeight() * 3/4);
	SetTextColor(pressStartColor);
	SetTextOutline(outlineColor, textOutlineThickness);
}

