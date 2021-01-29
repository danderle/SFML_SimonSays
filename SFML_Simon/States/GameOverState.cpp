#include "GameOverState.h"

GameOverState::GameOverState(std::shared_ptr<GameData> _gameData, Field& _field, const unsigned int _score)
	:
	gameData(_gameData),
	field(_field),
	scoreLabelText("Score"),
	scoreText(std::to_string(_score)),
	score(_score)
{
	SetupText();
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
		SaveTopScore();
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
	topScoreLabelText.Draw(gameData->Window);
	topScoreText.Draw(gameData->Window);
    scoreLabelText.Draw(gameData->Window);
	scoreText.Draw(gameData->Window);
	gameData->Window.display();

}

void GameOverState::SetupText()
{
	topScore = FileHandler::ReadHighScoreFromFile();
	topScoreLabelText.setString("Top Score");
	topScoreText.setString(std::to_string(topScore));
	topScoreLabelText.setCharacterSize(characterSize);
	topScoreText.setCharacterSize(characterSize);
	topScoreLabelText.setPosition(margin, margin);
	topScoreText.setPosition(margin + topScoreLabelText.GetWidth()/2, topScoreLabelText.GetHeight() + margin);

	scoreLabelText.setCharacterSize(characterSize);
	scoreText.setCharacterSize(characterSize);
	auto width = scoreLabelText.GetWidth();
	auto windowSize = gameData->Window.getSize();
	scoreLabelText.setPosition(windowSize.x - width - margin, margin);
	auto& labelPos = scoreLabelText.getPosition();
	scoreText.setPosition(labelPos.x + width / 2 - scoreText.GetWidth() / 2, labelPos.y + scoreLabelText.GetHeight() + margin);
}

void GameOverState::SaveTopScore() const
{
	auto highesScore = topScore > score ? topScore : score;
	FileHandler::WriteHighScoreToFile(highesScore);
}
