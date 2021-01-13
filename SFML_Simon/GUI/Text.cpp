#include "Text.h"

Text::Text()
{
    if (!font.loadFromFile(fontFilePath))
    {
        //Some error hadnling
    }
    text.setFont(font);
}

float Text::GetHeight() const
{
    return text.getLocalBounds().height;
}

void Text::SetCenterPosition(const float x, const float y)
{
    auto centerX = text.getGlobalBounds().left + text.getGlobalBounds().width / 2;
    auto centerY = text.getGlobalBounds().top + text.getGlobalBounds().height / 2;
    text.setOrigin(centerX, centerY);
    text.setPosition(x, y);
}

void Text::SetColor(const sf::Color color)
{
    text.setFillColor(color);
}

void Text::SetTopLeftPosition(const float x, const float y)
{
    auto leftX = text.getGlobalBounds().left + text.getGlobalBounds().width / 2;
    auto topY = text.getGlobalBounds().top + text.getGlobalBounds().height / 2;
    text.setOrigin(leftX, topY);
    text.setPosition(x, y);
}

void Text::SetString(const std::string& str)
{
    text.setString(str);
}

void Text::Draw(sf::RenderWindow& window)
{
    window.draw(text);
}
