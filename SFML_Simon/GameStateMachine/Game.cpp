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
    bool adding = true;

    float dt;
    float frameTime;
    float currentTime = clock.getElapsedTime().asSeconds();
    float fps;
    while (gameData->Window.isOpen())
    {
        sf::Event event;
        while (gameData->Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameData->Window.close();
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (!field.IsGameStarted())
                {
                    if (field.StartButtonPressed(gameData->Input.GetMousePosition(gameData->Window)))
                    {
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

        adding = field.IsMathchedSequence() && !field.IsSomeButtonPulsing();
        if (adding)
        {
            pattern.Add();
            field.SetSequence(pattern.Get());
            adding = false;
        }
        field.RunSequence();

        frameTime = clock.restart().asSeconds();
        fps = 1.f / frameTime;
        dt = frameTime / fps;
        while (fps > 0)
        {
            field.Update(dt);
            gameData->Window.clear();
            field.Draw(gameData->Window);
            gameData->Window.display();
            fps--;
        }
    }

}

//Private Functions

void Game::Setup()
{
    gameData->Window.create(sf::VideoMode(800, 800), "Simon Says!", sf::Style::Close | sf::Style::Titlebar);
    gameData->Window.setVerticalSyncEnabled(true);

    //Set window position relative to desktop size
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    gameData->Window.setPosition({ (int)desktop.width / 2 - (int)gameData->Window.getSize().x / 2, 0 });

}
