#include "GameOverState.h"

GameOverState::GameOverState(std::shared_ptr<GameData> _gameData, Field& _field, const unsigned int score)
	:
	gameData(_gameData),
	field(_field)
{
}

void GameOverState::HandleInput()
{
}

void GameOverState::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::MouseButtonReleased)
	{
		return;
	}
	auto mousePosition = gameData->Input.GetMousePosition(gameData->Window);
	if (field.CenterIsPressed(mousePosition))
	{
		field.PressToPlay();
		gameData->Machine.RemoveState();
	}
}

void GameOverState::Update(float dt)
{
	field.Update(dt);
}

void GameOverState::Draw()
{
	gameData->Window.clear();
	field.Draw(gameData->Window);
	gameData->Window.display();

}
