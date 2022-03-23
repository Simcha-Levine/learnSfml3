#include "Ground.hpp"
#include <iostream>

Ground::Ground(b2World &world, float scale, float x, float y, float width, float hight)
    : scale(scale), x(x), y(y), width(width), hight(hight),
      world(world),
      groundBody(createGround()),
      rect(sf::Vector2f(width * scale, hight * scale))
{
    rect.setPosition(sf::Vector2f(x * scale - (width * scale / 2), y * scale - (hight * scale / 2)));
    rect.setFillColor(sf::Color::Blue);
}

b2Body *Ground::createGround()
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(x, y);
    groundBodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);

    b2Body *groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(width / 2, hight / 2);

    groundBody->CreateFixture(&groundBox, 0.f);

    return groundBody;
}

void Ground::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    target.draw(rect);
}

void Ground::onDetection(std::string)
{
    // std::cout << "detected ground" << o << '\n';
}