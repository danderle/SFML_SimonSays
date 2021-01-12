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

	const bool IsSomeButtonPulsing() const;

	/// <summary>
	/// Signals to the user game is ready to start
	/// </summary>
	void PressToPlay();

	/// <summary>
	/// Show the pattern sequence to the user to be repeated
	/// </summary>
	void RunSequence();

	/// <summary>
	/// Sets the current pattern sequence
	/// </summary>
	/// <param name="seq"></param>
	void SetSequence(const std::vector<unsigned int>& seq);

	/// <summary>
	/// If the user presses the signaling start button the game will start
	/// </summary>
	/// <param name="mousePosition"></param>
	/// <returns></returns>
	const bool StartButtonPressed(const sf::Vector2i mousePosition);

	/// <summary>
	/// When its the users turn to repeat the sequence with the correct pattern
	/// </summary>
	/// <param name="mousePosition"></param>
	void EnterSequence(const sf::Vector2i mousePosition);

	void ResetAllButtons();

	/// <summary>
	/// Flag to let us know if the pattern sequence is correctly matched
	/// </summary>
	/// <returns></returns>
	const bool IsMathchedSequence() const;

	void Draw(sf::RenderWindow& window);

	void Update(const float dt);
private:
	std::vector<Button> buttons;
	sf::CircleShape middle;
	std::vector<unsigned int> sequence;
	bool runSequence = false;
	bool enteringSequence = false;
	bool matchedSequence = false;
	bool isGameStarted = false;
	unsigned int sequenceIndex = 0;
};

