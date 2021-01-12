#include "RoundedQuarterCircle.h"

QuarterCircle::QuarterCircle(const sf::Vector2f& _size, const unsigned int _cornerPointCount)
	:
	size(_size),
    cornerPointCount(_cornerPointCount),
    radius(20)
{
    setOutlineThickness(-5);
    setOutlineColor(sf::Color::Black);
    update();
}

void QuarterCircle::SetSize(const sf::Vector2f& _size)
{
	size = _size;
    update();
}

const sf::Vector2f& QuarterCircle::GetSize() const
{
	return size;
}

void QuarterCircle::SetPointCount(unsigned int count)
{
    cornerPointCount = count;
    update();
}

std::size_t QuarterCircle::getPointCount() const
{
	return cornerPointCount * 6;
}

sf::Vector2f QuarterCircle::getPoint(std::size_t index) const
{
    if (index >= cornerPointCount * 6)
        return sf::Vector2f(0, 0);

    //Basic data setup to calculate the point
    float angleIncrements = 90.f / (cornerPointCount - 1);
    float angle;
    static const float pi = 3.141592654f;
    unsigned int currentIndex = index / cornerPointCount;
    sf::Vector2f point;

    //the points are viewed clockwise
    switch (currentIndex)
    {
    case 0:
        angle = angleIncrements * index;
        point.x = radius - radius * cos(angle * pi / 180);
        point.y = radius - radius * sin(angle * pi / 180);
        break;
    case 1:
        angle = 90.f - angleIncrements * (index - cornerPointCount);
        point.x = (size.x - radius) * cos(angle * pi / 180) + radius;
        point.y = -size.y * sin(angle * pi / 180) + size.y;
        if (point.y > size.y - radius)
        {
            point.x = size.x;
            point.y = size.y - radius;
        }
        break;
    case 2:
        angle = 360.f - angleIncrements * (index -  2 * cornerPointCount);
        point.x = (size.x - radius) + cos(angle * pi / 180) * radius;
        point.y = (size.y - radius) - sin(angle * pi / 180) * radius;
        break;
    case 3:
        angle = 90.f - angleIncrements * (index - 3 * cornerPointCount);
        point.x = (size.x / 4 + radius) - radius * cos(angle * pi / 180);
        point.y = size.y - radius + radius * sin(angle * pi / 180);
        break;
    case 4:
        angle = angleIncrements * (index - 4 * cornerPointCount);
        point.x = (size.x/4 - radius) * cos(angle * pi / 180) + radius;
        point.x = point.x < radius ? radius : point.x;
        point.y = (size.y - radius) - (size.y / 4 - radius)* sin(angle * pi / 180);
        point.y = point.y < size.y * (3.f / 4) ? size.y * (3.f / 4) : point.y;
        break;
    case 5:
        angle = 270.f - angleIncrements * (index - 5 * cornerPointCount);
        point.x = (1 + cos(angle * pi / 180)) * radius;
        point.y = 3.f/4 * size.y - radius;
        point.y = (size.y * (3.f/4)) - radius * ( 1 + sin(angle * pi / 180));
        break;
    }
    
    return point;
}
