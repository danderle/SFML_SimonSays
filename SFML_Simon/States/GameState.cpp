#include "GameState.h"

GameState::GameState(std::shared_ptr<GameData> _gameData)
    :
    gameData(_gameData),
    field(gameData->Window)
{
    field.PressToPlay();
}

void GameState::HandleInput()
{
}

void GameState::HandleInput(const sf::Event& event)
{
    if (event.type != sf::Event::MouseButtonReleased)
    {
        return;
    }
    auto position = gameData->Input.GetMousePosition(gameData->Window);
    if (field.IsInBounds(sf::Vector2f(position)))
    {
        if (field.CenterIsPressed(position))
        {
            //Ignore middle presses
            return;
        }
        if (!field.IsGameStarted())
        {
            //true to start game
            if (field.StartButtonPressed(position))
            {
                pattern.Clear();
                pattern.Add();
                field.SetSequence(pattern.Get());
            }
        }
        else
        {
            field.EnterSequence(gameData->Input.GetMousePosition(gameData->Window));
        }
    }
}

void GameState::Update(float dt)
{
    adding = field.IsMathchedSequence() && !field.IsSomeButtonPulsing();
    if (adding)
    {
        pattern.Add();
        field.SetSequence(pattern.Get());
        adding = false;
    }
    field.RunSequence();
    field.Update(dt);
}

void GameState::Draw()
{
    gameData->Window.clear();
    field.Draw(gameData->Window);
    gameData->Window.display();
}
