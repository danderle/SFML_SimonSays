#include "GameOverState.h"

GameOverState::GameOverState(std::shared_ptr<GameData> _gameData, Field& _field, const unsigned int score)
	:
	gameData(_gameData),
	field(_field),
	scoreLabelText("Score"),
	scoreText(std::to_string(score))
{
	scoreLabelText.setCharacterSize(characterSize);
	scoreText.setCharacterSize(characterSize);
	auto width = scoreLabelText.GetWidth();
	auto windowSize = gameData->Window.getSize();
	scoreLabelText.setPosition(windowSize.x - width - margin, margin);
	auto labelPos = scoreLabelText.getPosition();
	scoreText.setPosition(labelPos.x + width / 2 - scoreText.GetWidth() / 2, labelPos.y + scoreLabelText.GetHeight() + margin);
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
	scoreLabelText.Draw(gameData->Window);
	scoreText.Draw(gameData->Window);
	gameData->Window.display();

}
