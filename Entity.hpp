#ifndef ENTITY
#define ENTITY

#include <string>
#include <iostream>
class Entity
{
private:
public:
    std::string name = "normal";
    char c = 'o';

    virtual void onDetection(std::string otherName) = 0;

    virtual ~Entity() {}
};

#endif