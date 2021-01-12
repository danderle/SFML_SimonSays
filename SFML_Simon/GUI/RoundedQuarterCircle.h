#pragma once
#include "SFML/Graphics/Shape.hpp"
#include <cmath>

class QuarterCircle : public sf::Shape
{
public:
    QuarterCircle(const sf::Vector2f& _size, const unsigned int _cornerPointCount);

    void SetSize(const sf::Vector2f& _size);
    const sf::Vector2f& GetSize() const;
    void SetPointCount(unsigned int count);

    /// <summary>
    /// Overriden method from the shape class, which returns the point count for the corners
    /// </summary>
    /// <returns></returns>
    virtual std::size_t getPointCount() const override;

    /// <summary>
    /// Overriden method from the shape class, which return a point from a given index
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    virtual sf::Vector2f getPoint(std::size_t index) const override;

private:
    sf::Vector2f size;
    float radius;
    unsigned int cornerPointCount;
};

