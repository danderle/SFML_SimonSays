#include "Game.h"

Game::Game()
{
	Setup();
    gameData->Machine.AddState(std::make_unique<SplashScreenState>(gameData));
    gameData->Machine.ProcessStateChanges();
}

void Game::Run()
{
    float dt;
    while (gameData->Window.isOpen())
    {
        sf::Event event;
        while (gameData->Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameData->Window.close();
            }
            else
            {
                gameData->Machine.GetActiveState()->HandleInput(event);
            }
        }

        gameData->Machine.ProcessStateChanges();
        gameData->Machine.GetActiveState()->HandleInput();

        //get delta time
        dt = clock.restart().asSeconds();
        gameData->Machine.GetActiveState()->Update(dt);
        gameData->Machine.GetActiveState()->Draw();
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
    
    //Set icon top left and taskbar
    icon.loadFromFile(iconFilePath);
    sf::Vector2u iconSize = icon.getSize();
    gameData->Window.setIcon(iconSize.x, iconSize.y, icon.getPixelsPtr());

    FileHandler::CreateAppDataDirectory();
}
