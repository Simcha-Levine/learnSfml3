#include "Axis.hpp"
#include <iostream>

Axis::Axis() : lines(new sf::RectangleShape[4])
{
    lines[0] = sf::RectangleShape(sf::Vector2f(1000, 1));
    lines[0].setFillColor(sf::Color(255, 255, 255, 255));

    lines[1] = sf::RectangleShape(sf::Vector2f(-1000, 1));
    lines[1].setFillColor(sf::Color(255, 255, 255, 255));

    lines[2] = sf::RectangleShape(sf::Vector2f(2, 1000));
    lines[2].setFillColor(sf::Color(255, 255, 255, 255));

    lines[3] = sf::RectangleShape(sf::Vector2f(2, -1000));
    lines[3].setFillColor(sf::Color(255, 255, 255, 255));
}

Axis::~Axis()
{
    delete[] lines;
}

void Axis::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    for (size_t i = 0; i < 4; i++)
    {
        target.draw(lines[i]);
    }
}
