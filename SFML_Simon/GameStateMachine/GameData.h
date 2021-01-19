#pragma once
#include "SFML/Graphics.hpp"
#include "InputManager.h"
#include "StateMachine.h"

/// <summary>
/// Structure represents all the available game data options
/// </summary>
struct GameData
{
	sf::RenderWindow Window;
	InputManager Input;
	StateMachine Machine;
};