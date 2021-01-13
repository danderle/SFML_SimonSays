#pragma once
#include "SFML/Graphics.hpp"

class Text
{
public:
	Text();

	float GetHeight() const;

	void SetCenterPosition(const float x, const float y);
	void SetColor(const sf::Color color);
	void SetTopLeftPosition(const float x, const float y);
	void SetString(const std::string & str);

	void Draw(sf::RenderWindow& window);
private:
	sf::Text text;
	sf::Font font;

	const std::string fontFilePath = "Resources\\Fonts\\Unispace-Rg.ttf";
};

