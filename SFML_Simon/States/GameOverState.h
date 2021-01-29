#pragma once
#include "IState.h"
#include "GameData.h"
#include "Field.h"
#include "Text.h"
#include "FileHandler.h"

class GameOverState : public IState
{
public:
	GameOverState(std::shared_ptr<GameData> _gameData, Field& _field, const unsigned int score);

	void HandleInput() override;
	void HandleInput(const sf::Event& event) override;
	void Update(float dt) override;
	void Draw() override;
	void Pause() {}
	void Resume() {}

private:
	void SetupText();
	void SaveTopScore() const;
private:
	std::shared_ptr<GameData> gameData;
	Field& field;

	Text scoreLabelText;
	Text scoreText;
	Text topScoreLabelText;
	Text topScoreText;
	size_t topScore = 0;
	size_t score = 0;

	static constexpr unsigned int characterSize = 50;
	static constexpr float margin = 10.f;
};

