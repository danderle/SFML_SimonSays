#pragma once
#include <memory>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "InputManager.h"
#include "Field.h"
#include "Pattern.h"

/// <summary>
/// Structure represents all the available game data options
/// </summary>
struct GameData
{
	sf::RenderWindow Window;
	InputManager Input;
};

/// <summary>
/// Game class is responsible for initalization and running the game loop
/// </summary>
class Game
{
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	Game();

	/// <summary>
	/// The game loop
	/// </summary>
	void Run();

private:
	void Setup();

private:
	sf::Clock clock;
	std::shared_ptr<GameData> gameData = std::make_shared<GameData>();
};

