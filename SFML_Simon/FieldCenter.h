#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"
#include <assert.h>

enum class State
{
	PressToStart,
	SimonSays,
	PleaseRepeat,
	GameOver,
	PressToContinue
};

class FieldCenter
{
public:
	FieldCenter(const sf::Vector2f windowSize);

	bool Contains(const sf::Vector2f mousePosition) const;
	void Draw(sf::RenderWindow& window);
	void SetState(const State State);
	const State GetState() const;
	void ColorTransition(const float dt);

private:
	void ToggleText();
	void Blink();
	void StopBlink();
	void CenterText();
	void SetRgbMin(sf::Uint8 r, sf::Uint8 g, sf::Uint16 b);
	void SetRgbMax(sf::Uint8 r, sf::Uint8 g, sf::Uint16 b);
	void SetTextColor(const sf::Color color);
	void SetTextOutline(const sf::Color color, const float thickness);
	void SetupCircle(const sf::Vector2f windowSize);
	void SetupTexts(const sf::Vector2f windowSize);
	void DecreaseRGB(const float dt);
	void IncreaseRGB(const float dt);

private:
	sf::CircleShape circle;
	sf::Vector2f centerPoint;
	sf::Uint8 rMin;
	sf::Uint8 gMin;
	sf::Uint8 bMin;
	sf::Uint8 rMax;
	sf::Uint8 gMax;
	sf::Uint8 bMax;

	Text firstLine;
	Text secondLine;
	State currentState;
	bool isBlinking = false;
	bool decreaseRgb = false;
	bool increaseRgb = false;
	bool toggleText = false;
	float colortimePassed = 0;
	float toggletimePassed = 0;

	const sf::Color defaultColor = { 192,192,192 };
	static constexpr float toggleTransitionTimeout = 2.f;
	static constexpr float colorTransitionTimeout = 0.1f;
	static constexpr float circleRadius = 98.f;
	static constexpr float circleOutlineThickness = -8.f;
	static constexpr float textOutlineThickness = 1.f;
	static constexpr sf::Uint8 colorSteps = 25;
	const sf::Color outlineColor = sf::Color::Black;
	const sf::Color pressStartColor = sf::Color::Black;
	const sf::Color simonsSaysColor = sf::Color(255, 0, 255);
	const sf::Color pleaseRepeatColor = sf::Color(255, 128, 0);
	const sf::Color gameOverColor = sf::Color(255, 0, 0);
};

