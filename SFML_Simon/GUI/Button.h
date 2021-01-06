#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cassert>

/// <summary>
/// Class represent a button
/// </summary>
class Button
{
public:
	Button() = delete;
	Button(const float width, const float height, const float xPos, const float yPos);
	Button(const sf::Vector2f size, const sf::Vector2f position);


	const bool Contains(sf::Vector2f position);
	const bool Contains(sf::Vector2i position);

	void LoadSound(std::string fileName);
	void PlaySound();
	void StopSound();

	/// <summary>
	/// Set the default background color
	/// </summary>
	/// <param name="color"></param>
	void SetColor(const sf::Color color);

	/// <summary>
	/// Set the min rgb values when using the hover effect
	/// </summary>
	/// <param name="r"></param>
	/// <param name="g"></param>
	/// <param name="b"></param>
	void SetMinRGB(const sf::Uint8 r, const sf::Uint8 g, const sf::Uint8 b);

	/// <summary>
	/// Set the max values for using the hover effect
	/// </summary>
	/// <param name="r"></param>
	/// <param name="g"></param>
	/// <param name="b"></param>
	void SetMaxRGB(const sf::Uint8 r, const sf::Uint8 g, const sf::Uint8 b);

	void SetHover(const bool isHovering);

	void StartPulse();
	void StartContinousPulse();

	/// <summary>
	/// tranistions the color when hovering
	/// </summary>
	/// <param name="dt"></param>
	void ColorTransition(const float dt);

	bool IsPulsing() const;
	bool IsFinished() const;
	void Pulse(const float dt);
	void Reset();

	const unsigned int GetIndex() const;
	sf::FloatRect GetRect() const;

	void Draw(sf::RenderWindow& window);

private:
	void IncreaseRGB(const float dt);
	void DecreaseRGB(const float dt);

private:
	sf::RectangleShape shape;
	sf::Color startingColor;
	sf::Uint8 rMin;
	sf::Uint8 gMin;
	sf::Uint8 bMin;
	sf::Uint8 rMax;
	sf::Uint8 gMax;
	sf::Uint8 bMax;
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	bool hover = false;
	bool continousPulse = false;
	bool isPulsing = false;
	bool isFinished = false;
	bool increaseRgb = false;
	bool decreaseRgb = false;
	float colortimePassed = 0;
	unsigned int index = 0;

private:
	static constexpr float colorTransitionTimeout = 0.1f;
	static constexpr sf::Uint8 colorSteps = 50;
	static unsigned int totalIndex;
};

