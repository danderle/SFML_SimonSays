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
