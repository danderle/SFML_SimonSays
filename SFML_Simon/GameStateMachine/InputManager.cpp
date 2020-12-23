#include "InputManager.h"

bool InputManager::RectHover(sf::Rect<float> rect, sf::RenderWindow& window)
{
	auto mousePosition = GetMousePosition(window);
	auto floatVec = sf::Vector2f(mousePosition);
	return rect.contains(floatVec);
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) const
{
	auto mousePosition = sf::Mouse::getPosition(window);
	return mousePosition;
}

bool InputManager::IsRectClicked(sf::Rect<float> rect, sf::Mouse::Button buttonPressed, sf::RenderWindow& window)
{
	bool isClicked = false;
	if (sf::Mouse::isButtonPressed(buttonPressed))
	{
		isClicked = IsMouseInsideRect(rect, window);
	}
	return isClicked;
}

bool InputManager::IsMouseInsideRect(sf::Rect<float> rect, sf::RenderWindow& window)
{
	bool isInside = false;
	auto msePosition = GetMousePosition(window);
	if (rect.contains({ (float)msePosition.x, (float)msePosition.y }))
	{
		isInside = true;
	}
	return isInside;
}

