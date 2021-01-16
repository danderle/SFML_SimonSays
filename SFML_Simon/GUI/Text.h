#pragma once
#include "SFML/Graphics.hpp"

class Text
{
public:
	Text();

	float GetHeight() const;

	void SetPosition(const float x, const float y);
	void SetPosition(const sf::Vector2f position);
	void SetColor(const sf::Color color);
	void SetOriginToCenter();
	void SetOutlineColor(const sf::Color color);
	void SetOutlineThickness(const float thickness);
	void SetOriginToTopLeft();
	void SetString(const std::string & str);
	void SetXposition(const float x);

	void Draw(sf::RenderWindow& window);
private:
	sf::Text text;
	sf::Font font;

	const std::string fontFilePath = "Resources\\Fonts\\Unispace-Rg.ttf";
};

