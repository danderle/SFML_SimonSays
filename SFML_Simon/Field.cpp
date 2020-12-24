#include "Field.h"

Field::Field(sf::RenderWindow& window)
    :
    sequence({ 0,1,2,3,3,2,1,0 })
{
    auto windowSize = sf::Vector2f(window.getSize());
    auto buttonSize = (float)windowSize.x / 3;

    Button buttonR(buttonSize, buttonSize, windowSize.x / 2 - buttonSize, windowSize.y / 2 - buttonSize);
    buttonR.SetColor(sf::Color::Red);
    buttonR.SetMaxRGB(255, 205, 205);
    buttonR.SetMinRGB(255, 0, 0);

    Button buttonG(buttonSize, buttonSize, windowSize.x / 2, windowSize.y / 2 - buttonSize);
    buttonG.SetColor(sf::Color::Green);
    buttonG.SetMaxRGB(205, 255, 205);
    buttonG.SetMinRGB(0, 255, 0);

    Button buttonB(buttonSize, buttonSize, windowSize.x / 2, windowSize.y / 2);
    buttonB.SetColor(sf::Color::Blue);
    buttonB.SetMaxRGB(205, 205, 255);
    buttonB.SetMinRGB(0, 0, 255);

    Button buttonY(buttonSize, buttonSize, windowSize.x / 2 - buttonSize, windowSize.y / 2);
    buttonY.SetColor(sf::Color::Yellow);
    buttonY.SetMaxRGB(255, 255, 205);
    buttonY.SetMinRGB(255, 255, 0);

    buttons.push_back(buttonR);
    buttons.push_back(buttonG);
    buttons.push_back(buttonB);
    buttons.push_back(buttonY);
}

void Field::ShowSequence(const float dt)
{
    if(sequenceRunning)
    {
        auto& button = buttons[sequence[sequenceIndex]];
        if (button.IsFinished())
        {
            button.Reset();
            sequenceIndex = ++sequenceIndex < sequence.size() ? sequenceIndex : 0;
            sequenceRunning = false;
            enteringSequence = true;
        }
        else if (!button.IsPulsing())
        {
            button.StartPulse();
        }
    }
    for (auto& button : buttons)
    {
        button.ColorTransition(dt);
    }
}

void Field::EnterSequence(const sf::Vector2i mousePosition)
{
    if (!enteringSequence)
    {
        return;
    }
    for (auto& button : buttons)
    {
        if (button.GetRect().contains(sf::Vector2f(mousePosition)))
        {
            if (sequence[sequenceIndex] == button.GetIndex())
            {
                button.StartPulse();
                sequenceIndex++;
                if (sequenceIndex == sequence.size())
                {
                    enteringSequence = false;
                    sequenceRunning = true;
                }
            }
            else
            {
                for (auto& btn : buttons)
                {
                    btn.StartPulse();
                }
                enteringSequence = false;
            }
            break;
        }
    }
}

void Field::Draw(sf::RenderWindow& window)
{
    for (auto& button : buttons)
    {
        button.Draw(window);
    }
}
