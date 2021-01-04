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

const bool Field::IsGameStarted() const
{
    return isGameStarted;
}

const bool Field::IsSomeButtonPulsing() const
{
    bool stillPulsing = false;
    for (auto button : buttons)
    {
        stillPulsing = button.IsPulsing();
        if (stillPulsing)
        {
            break;
        }
    }
    return stillPulsing;
}

void Field::PressToPlay()
{
    assert(buttons.size() > 0);
    buttons[0].StartContinousPulse();
}

void Field::RunSequence()
{
    if (!runSequence)
    {
        return;
    }
    auto& button = buttons[sequence[sequenceIndex]];
    //if button is finished pulsing, increase sequence index
    if (button.IsFinished())
    {
        button.Reset();
        sequenceIndex = ++sequenceIndex;
        //if the end of the sequence is reached its time for the user to repeat
        if (sequenceIndex >= sequence.size())
        {
            runSequence = false;
            enteringSequence = true;
            sequenceIndex = 0;
        }
    }
    //start button pulse
    else if (!button.IsPulsing())
    {
        button.StartPulse();
    }
}

void Field::SetSequence(const std::vector<unsigned int>& seq)
{
    //set the new sequence and flags to show pattern sequence to user
    sequence = seq;
    runSequence = true;
    matchedSequence = false;
    sequenceIndex = 0;
    ResetAllButtons();
}

const bool Field::StartButtonPressed(const sf::Vector2i mousePosition)
{
    //if game has not started and the signaling button is pressed, start the game
    if (buttons[0].Contains(mousePosition))
    {
        buttons[0].Reset();
        isGameStarted = true;
    }
    return isGameStarted;
}

void Field::EnterSequence(const sf::Vector2i mousePosition)
{
    if (!enteringSequence)
    {
        return;
    }
    for (auto& button : buttons)
    {
        if (button.Contains(mousePosition))
        {
            //std::cout << "You entered: " << button.GetIndex() << " Correct is: " << sequence[sequenceIndex] << std::endl;

            //correct sequence
            if (sequence[sequenceIndex] == button.GetIndex())
            {
                button.StartPulse();
                sequenceIndex++;
                //was last in sequence
                if (sequenceIndex >= sequence.size())
                {
                    enteringSequence = false;
                    matchedSequence = true;
                    sequenceIndex = 0;
                }
            }
            //wrong sequence
            else
            {
                for (auto& btn : buttons)
                {
                    btn.StartPulse();
                }
                enteringSequence = false;
                isGameStarted = false;
                PressToPlay();
            }
            break;
        }
    }
}

void Field::ResetAllButtons()
{
    for (auto& button : buttons)
    {
        button.Reset();
    }
}

const bool Field::IsMathchedSequence() const
{
    return matchedSequence;
}

void Field::Draw(sf::RenderWindow& window)
{
    for (auto& button : buttons)
    {
        button.Draw(window);
    }
}

void Field::Update(const float dt)
{
    for (auto& button : buttons)
    {
        button.ColorTransition(dt);
    }
}
