#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// Class represent a button
/// </summary>
class Button
{
public:
	Button() = delete;
	Button(const float width, const float height, const float xPos, const float yPos);
	Button(const sf::Vector2f size, const sf::Vector2f position);

	void SetColor(const sf::Color color);
	void Draw(sf::RenderWindow& window);
private:
	sf::RectangleShape shape;

};

