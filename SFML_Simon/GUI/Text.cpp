#include "Text.h"

Text::Text()
{
    if (!font.loadFromFile(fontFilePath))
    {
        //Some error hadnling
    }
    setFont(font);
}

Text::Text(const std::string& _text)
    :Text()
{
    setString(_text);
}

float Text::GetHeight() const
{
    return getLocalBounds().height;
}

float Text::GetWidth() const
{
    return getLocalBounds().width;;
}

void Text::SetColor(const sf::Color color)
{
    setFillColor(color);
}

void Text::SetOriginToCenter()
{
    auto centerX = getLocalBounds().left + getGlobalBounds().width / 2;
    auto centerY = getLocalBounds().top + getGlobalBounds().height / 2;
    setOrigin(centerX, centerY);
}

void Text::SetOutlineColor(const sf::Color color)
{
    setOutlineColor(color);
}

void Text::SetOutlineThickness(const float thickness)
{
    setOutlineThickness(thickness);
    auto f = getOutlineThickness();
}

void Text::SetOriginToTopLeft()
{
    auto leftX = getLocalBounds().left;
    auto topY = getLocalBounds().top;
    setOrigin(leftX, topY);
}

void Text::SetString(const std::string& str)
{
    setString(str);
}

void Text::SetXposition(const float x)
{
    setPosition(x, getPosition().y);
}

void Text::Draw(sf::RenderWindow& window)
{
    window.draw(*this);
}
