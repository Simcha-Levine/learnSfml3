#include "Poly.hpp"
#include <iostream>

int corners = 20;

Poly::Poly(b2World &world, float scale, float x, float y, float width)
    : scale(scale), x(x), y(y), width(width),
      world(world),
      body(createBody()),
      vertices(sf::TriangleFan, corners + 1)
{

    // std::srand(time(nullptr));
    float firstAngle = 0;
    float firstR = 200;

    for (int i = 0; i < corners; i++)
    {
        int min = (width * scale / 2) * 0.5;
        int max = width * scale / 2;
        float r = min + rand() % (max - min);

        float section = M_PI * 2 / corners;
        float range = section / 3;
        float add = -range + float(std::rand()) / float(RAND_MAX / (range * 2));
        double angle = section * i + add;
        vertices[i].position = sf::Vector2f(r * cos(angle), r * sin(angle));

        if (i == 0)
        {
            firstAngle = angle;
            firstR = r;
        }
    }
    vertices[corners].position = sf::Vector2f(firstR * cos(firstAngle), firstR * sin(firstAngle));

    createShapes();
}

b2Body *Poly::createBody()
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);

    b2Body *body = world.CreateBody(&bodyDef);

    return body;
}

void Poly::createShape(int i)
{

    if (i < corners)
    {
        b2Vec2 ver[3];
        ver[0].Set(vertices[i].position.x / scale, vertices[i].position.y / scale);
        ver[1].Set(vertices[i + 1].position.x / scale, vertices[i + 1].position.y / scale);
        ver[2].Set(0.f, 0.f);

        b2PolygonShape poly;
        poly.Set(ver, 3);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &poly;
        fixtureDef.density = 1.f;
        fixtureDef.friction = 0.5f;
        fixtureDef.restitution = 0.5f;

        body->CreateFixture(&fixtureDef);
    }
}

void Poly::createShapes()
{
    for (int i = 0; i < corners; i++)
    {
        createShape(i);
    }
}

void Poly::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(vertices, states);
}

void Poly::update()
{
    b2Vec2 pos = body->GetPosition();
    setPosition(sf::Vector2f(pos.x * scale, pos.y * scale));
    float deg = body->GetAngle() * (180.f / M_PI);
    setRotation(deg);
}

void Poly::setColor(sf::Color color)
{
    for (int i = 0; i < corners + 1; i++)
    {
        vertices[i].color = color;
    }
}

void Poly::onDetection(std::string o)
{
    if (o == "barrier")
    {
        toOld = true;
    }
}

Poly::~Poly()
{
    world.DestroyBody(body);
    // std::cout << "poly destroid\n";
}