#pragma once
#include "IState.h"
#include "GameData.h"
#include "GameState.h"

class SplashScreenState : public IState
{
public:
	SplashScreenState(std::shared_ptr<GameData> _gameData);

	void HandleInput() override;
	void HandleInput(const sf::Event& event) override;
	void Update(float dt) override;
	void Draw() override;
	void Pause() {}
	void Resume() {}

private:
	std::shared_ptr<GameData> gameData;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sound sound;
	sf::SoundBuffer buffer;
	static constexpr float splashScreenDisplayTime = 3.f;
	const std::string splashScreenFilePath = "Resources\\Images\\SimonSaysSplashScreen.png";
	const std::string introSoundFilePath = "Resources\\Sounds\\splashScreenIntro.wav";
};

