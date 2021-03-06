#pragma once
#include "IState.h"
#include "GameOverState.h"
#include "GameData.h"
#include "Field.h"
#include "Pattern.h"

class GameState : public IState
{
public:
	GameState(std::shared_ptr<GameData> _gameData);

	void HandleInput() override;
	void HandleInput(const sf::Event& event) override;
	void Update(float dt) override;
	void Draw() override;
	void Pause() {}
	void Resume() {}

private:
	std::shared_ptr<GameData> gameData;
	Field field;
	Pattern pattern;
};

