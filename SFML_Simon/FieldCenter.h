#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"

enum class Turn
{
	PressToStart,
	SimonSays,
	PleaseRepeat
};

class FieldCenter
{
public:
	FieldCenter(const sf::Vector2f windowSize);
	void Draw(sf::RenderWindow& window);
	void SetTurn(const Turn turn);

private:
	void SetTextColor(const sf::Color color);
	void SetupCircle(const sf::Vector2f windowSize);
	void SetupTexts(const sf::Vector2f windowSize);
private:
	sf::CircleShape circle;
	Text firstLine;
	Text secondLine;

	static constexpr float circleRadius = 98.f;
};

