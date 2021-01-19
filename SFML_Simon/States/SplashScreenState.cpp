#include "SplashScreenState.h"

SplashScreenState::SplashScreenState(std::shared_ptr<GameData> _gameData)
	:
	gameData(_gameData)
{
	if (!texture.loadFromFile(splashScreenFilePath))
	{
		//TODO some error handling
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	if (!buffer.loadFromFile(introSoundFilePath))
	{
		//TODO Error handling
	}
	sound.setBuffer(buffer);
	sound.play();
}

void SplashScreenState::HandleInput()
{
}

void SplashScreenState::HandleInput(const sf::Event& event)
{
}

void SplashScreenState::Update(float dt)
{
	if (sound.getStatus() != sf::Sound::Playing)
	{
		gameData->Machine.AddState(std::make_unique<GameState>(gameData));
	}
}

void SplashScreenState::Draw()
{
	gameData->Window.clear();
	gameData->Window.draw(sprite);
	gameData->Window.display();
}
