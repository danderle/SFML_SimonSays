#pragma once
#include "SFML/Graphics.hpp"
#include "InputManager.h"
#include "Button.h"
#include <vector>

class Field
{
public:
	Field(sf::RenderWindow& window);
	
	const bool IsGameStarted() const;
	const bool SomeButtonPulsing() const;
	void PressToPlay();
	void ShowSequence(const float dt);
	void SetSequence(const std::vector<unsigned int>& seq);
	const bool StartButtonPressed(const sf::Vector2i mousePosition);
	void EnterSequence(const sf::Vector2i mousePosition);
	void ResetAllButtons();

	const bool MathchedSequence() const;

	void Draw(sf::RenderWindow& window);
private:
	std::vector<Button> buttons;
	std::vector<unsigned int> sequence;
	bool runSequence = false;
	bool enteringSequence = false;
	bool matchedSequence = false;
	bool isGameStarted = false;
	unsigned int sequenceIndex = 0;
};

