#include "Game.h"

Game::Game()
{
	Setup();
}

void Game::Run()
{
    Field field(gameData->Window);
    field.PressToPlay();
    Pattern pattern;
    bool adding = false;

    float dt;
    while (gameData->Window.isOpen())
    {
        sf::Event event;
        while (gameData->Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameData->Window.close();
            if (event.type == sf::Event::MouseButtonReleased)
            {
                auto position = gameData->Input.GetMousePosition(gameData->Window);
                if (field.IsInBounds(sf::Vector2f(position)))
                {
                    if (field.CenterIsPressed(position))
                    {
                        //Ignore middle presses
                        continue;
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
        }

        adding = field.IsMathchedSequence() && !field.IsSomeButtonPulsing();
        if (adding)
        {
            pattern.Add();
            field.SetSequence(pattern.Get());
            adding = false;
        }
        field.RunSequence();

        //get delta time
        dt = clock.restart().asSeconds();

        field.Update(dt);
        gameData->Window.clear();
        field.Draw(gameData->Window);
        gameData->Window.display();
    }

}

//Private Functions

void Game::Setup()
{
    gameData->Window.create(sf::VideoMode(800, 800), "Simon Says!", sf::Style::Close | sf::Style::Titlebar);
    gameData->Window.setFramerateLimit(60);

    //Set window position relative to desktop size
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    gameData->Window.setPosition({ (int)desktop.width / 2 - (int)gameData->Window.getSize().x / 2, 0 });

}
