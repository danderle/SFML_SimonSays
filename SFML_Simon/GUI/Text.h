#pragma once
#include "SFML/Graphics.hpp"

class Text : public sf::Text
{
public:
	Text();
	Text(const std::string& _text);

	float GetHeight() const;
	float GetWidth() const;

	void SetColor(const sf::Color color);
	void SetOriginToCenter();
	void SetOutlineColor(const sf::Color color);
	void SetOutlineThickness(const float thickness);
	void SetOriginToTopLeft();
	void SetString(const std::string & str);
	void SetXposition(const float x);

	void Draw(sf::RenderWindow& window);
	
public:
private:
	sf::Font font;

	const std::string fontFilePath = "Resources\\Fonts\\Unispace-Rg.ttf";
};

