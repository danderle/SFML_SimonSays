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

	bool Contains(const sf::Vector2f mousePosition) const;
	void Draw(sf::RenderWindow& window);
	void SetTurn(const Turn turn);

private:
	void SetTextColor(const sf::Color color);
	void SetTextOutline(const sf::Color color, const float thickness);
	void SetupCircle(const sf::Vector2f windowSize);
	void SetupTexts(const sf::Vector2f windowSize);
private:
	sf::CircleShape circle;
	Text firstLine;
	Text secondLine;

	static constexpr float circleRadius = 98.f;
	static constexpr float circleOutlineThickness = -8.f;
	static constexpr float textOutlineThickness = 1.f;
	const sf::Color outlineColor = sf::Color::Black;
	const sf::Color pressStartColor = sf::Color::Black;
	const sf::Color simonsSaysColor = sf::Color(255, 0, 255);
	const sf::Color pleaseRepeatColor = sf::Color(255, 128, 0);
};

