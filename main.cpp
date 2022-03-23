#include "Ground.hpp"
#include "Body.hpp"
#include "Poly.hpp"
#include <iostream>
#include "Axis.hpp"
#include "ContactListener.hpp"

using namespace std;

int scale = 80;

int main()
{

    b2Vec2 gravity(0.f, -10.f);
    b2World world(gravity);

    ContactListener contactListener;
    world.SetContactListener(&contactListener);

    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "hello world");
    window.setVerticalSyncEnabled(true);
    window.setPosition(sf::Vector2i(800, 100));

    sf::View view(sf::FloatRect(0, 0, 2000, -2000));
    view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    view.setCenter(sf::Vector2f(0, 0));

    Ground ground(world, scale, 0.f, -5.f, 10, 1);

    Ground barrier(world, scale, 0.f, -8.f, 30, 0.5);
    barrier.name = "barrier";

    srand(time(nullptr));

    // vector<Body *> polys;
    vector<Poly *> polys;

    Axis axis;

    sf::Clock clock;
    sf::Clock timer;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime().asMilliseconds() > 200)
        {
            clock.restart();
            int r = rand() % 255;
            int g = rand() % 255;
            int b = rand() % 255;
            sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            polys.push_back(new Poly(world, scale, pos.x / scale, pos.y / scale, 2.f));
            polys.back()->setColor(sf::Color(r, g, b));
        }

        world.Step(timeStep, velocityIterations, positionIterations);
        // cout << timer.restart().asMilliseconds() << '\n';

        window.setView(view);

        window.clear();

        window.draw(ground);
        window.draw(barrier);

        for (size_t i = 0; i < polys.size(); i++)
        {
            auto poly = polys[i];
            poly->update();
            window.draw(*poly);
        }

        window.draw(axis);
        window.display();
    }
}