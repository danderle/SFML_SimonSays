#include "Game.h"

Game::Game()
{
	Setup();
}

void Game::Run()
{
    Button button1(200, 200, 200, 200);
    button1.SetColor(sf::Color::Green);
    button1.SetMaxRGB(225, 255, 205);
    button1.SetMinRGB(0, 255, 0);

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
        }

        frameTime = clock.restart().asSeconds();
        fps = 1.f / frameTime;
        dt = frameTime / fps;
        while (fps > 0)
        {
            bool hover = gameData->input.RectHover(button1.GetRect(), gameData->Window);
            std::cout << std::boolalpha << hover << std::endl;
            button1.SetHover(hover);
            button1.ColorTransition(dt);

            gameData->Window.clear();

            button1.Draw(gameData->Window);
        
            gameData->Window.display();
        }
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
