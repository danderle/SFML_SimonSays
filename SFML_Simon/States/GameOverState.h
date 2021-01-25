#pragma once
#include "IState.h"
#include "GameData.h"
#include "Field.h"
#include "Text.h"

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
	std::shared_ptr<GameData> gameData;
	Field& field;

	Text scoreLabelText;
	Text scoreText;
	static constexpr unsigned int characterSize = 50;
	static constexpr float margin = 10.f;
};

