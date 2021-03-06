#pragma once
#include "SFML/Graphics.hpp"

class IState
{
public:
	virtual void HandleInput() = 0;
	virtual void HandleInput(const sf::Event& event) = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual void Pause() {}
	virtual void Resume() {}
};

