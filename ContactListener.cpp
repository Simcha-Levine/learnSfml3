#include "ContactListener.hpp"
#include "Entity.hpp"
#include <iostream>

void ContactListener::BeginContact(b2Contact *contact)
{
    auto bodyUserDataA = (Entity *)(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
    auto bodyUserDataB = (Entity *)(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

    bodyUserDataA->onDetection(bodyUserDataB->name);
    bodyUserDataB->onDetection(bodyUserDataA->name);
}