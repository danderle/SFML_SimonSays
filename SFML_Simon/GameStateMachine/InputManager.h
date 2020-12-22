#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// Class handles all the input from a user
/// </summary>
class InputManager
{
public:
	InputManager() = default;
	~InputManager() = default;

	/// <summary>
	/// True if the mouse position is inside a given rectangle
	/// </summary>
	/// <param name="rect"></param>
	/// <param name="window"></param>
	/// <returns></returns>
	bool RectHover(sf::Rect<float> rect, sf::RenderWindow& window);
	sf::Vector2i GetMousePosition(sf::RenderWindow& window) const;

private:

};

