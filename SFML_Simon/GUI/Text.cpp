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

void Text::SetPosition(const float x, const float y)
{
    SetPosition({x,y});
}

void Text::SetPosition(const sf::Vector2f position)
{
    text.setPosition(position);
}

void Text::SetColor(const sf::Color color)
{
    text.setFillColor(color);
}

void Text::SetOriginToCenter()
{
    auto centerX = text.getLocalBounds().left + text.getGlobalBounds().width / 2;
    auto centerY = text.getLocalBounds().top + text.getGlobalBounds().height / 2;
    text.setOrigin(centerX, centerY);
}

void Text::SetOutlineColor(const sf::Color color)
{
    text.setOutlineColor(color);
}

void Text::SetOutlineThickness(const float thickness)
{
    text.setOutlineThickness(thickness);
    auto f = text.getOutlineThickness();
}

void Text::SetOriginToTopLeft()
{
    auto leftX = text.getLocalBounds().left;
    auto topY = text.getLocalBounds().top;
    text.setOrigin(leftX, topY);
}

void Text::SetString(const std::string& str)
{
    text.setString(str);
}

void Text::SetXposition(const float x)
{
    text.setPosition(x, text.getPosition().y);
}

void Text::Draw(sf::RenderWindow& window)
{
    window.draw(text);
}
