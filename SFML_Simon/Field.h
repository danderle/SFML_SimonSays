#pragma once
#include "SFML/Graphics.hpp"
#include "InputManager.h"
#include "Button.h"
#include <vector>

class Field
{
public:
	Field(sf::RenderWindow& window);
	
	void ShowSequence(const float dt);
	void EnterSequence(const sf::Vector2i mousePosition);

	void Draw(sf::RenderWindow& window);
private:
	std::vector<Button> buttons;
	std::vector<int> sequence;
	bool sequenceRunning = false;
	bool enteringSequence = true;
	unsigned int sequenceIndex = 0;
};

