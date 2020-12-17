#include "Game.h"

Game::Game()
{
	Setup();
}

void Game::Run()
{
    Button button1(200, 200, 200, 200);
    button1.SetColor(sf::Color::Green);
    Button button2(200, 200, 400, 200);
    button2.SetColor(sf::Color::Red);
    Button button3(200, 200, 200, 400);
    button3.SetColor(sf::Color::Blue);
    Button button4(200, 200, 400, 400);
    button4.SetColor(sf::Color::Yellow);

    while (gameData->Window.isOpen())
    {
        sf::Event event;
        while (gameData->Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameData->Window.close();
        }

        gameData->Window.clear();

        button1.Draw(gameData->Window);
        button3.Draw(gameData->Window);
        button4.Draw(gameData->Window);
        button2.Draw(gameData->Window);
        
        gameData->Window.display();
    }

}

void Game::Setup()
{
    gameData->Window.create(sf::VideoMode(800, 800), "Simon Says!", sf::Style::Close | sf::Style::Titlebar);
    //gameData->Window.setVerticalSyncEnabled(true);

    //Set window position relative to desktop size
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    gameData->Window.setPosition({ (int)desktop.width / 2 - (int)gameData->Window.getSize().x / 2, 0 });
}
