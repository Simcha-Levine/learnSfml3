#include "ContactListener.hpp"
#include "Entity.hpp"
#include <iostream>

void ContactListener::BeginContact(b2Contact *contact)
{
    std::cout << "hello\n";
    auto bodyUserDataA = (Entity *)(contact->GetFixtureA()->GetBody()->GetUserData().pointer);

    auto bodyUserDataB = (Entity *)(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

    bodyUserDataA->onDetection(bodyUserDataB->name);
    // std::cout << "A\n";
    bodyUserDataB->onDetection(bodyUserDataA->name);
    // std::cout << "B\n";
}